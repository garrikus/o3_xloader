/*
 * Copyright (C) 2005 Texas Instruments.
 *
 * (C) Copyright 2004
 * Jian Zhang, Texas Instruments, jzhang@ti.com.
 *
 * (C) Copyright 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>

extern int misc_init_r (void);
extern u32 get_mem_type(void);

#include <version_autogenerated.h>

#ifndef CFG_BTD_INDEX
#define CFG_BTD_INDEX ""
#endif

static const char version_string[] =
	"MLO-version-id: " X_LOADER_VERSION CFG_BTD_INDEX " (" __DATE__ " - " __TIME__ ")";

#ifdef CFG_PRINTF
int print_info(void)
{
	printf("\n\n%s\n", version_string);
	return 0;
}
#endif

/**
 * Initialize available memory
 */
int mem_init(void)
{
#ifdef CONFIG_AM3517EVM
	emif_init();
#else
	sdrc_init();
#endif
	return 0;
}

#ifdef CONFIG_MMC
#ifdef CONFIG_DRIVER_OMAP34XX_I2C
static int init_func_i2c(void)
{
	i2c_init(CFG_I2C_SPEED, CFG_I2C_SLAVE);
	return 0;
}

#define TWL4030_CHIP_PM_MASTER				0x4b
#define TWL4030_PM_MASTER_P1_SW_EVENTS			0x46

static inline void shutdown(void)
{
    int i;
    u8 value = 0x01;

    i2c_set_bus_num(0);

    for(i = 0; i < 3; i++)
	i2c_write(TWL4030_CHIP_PM_MASTER, TWL4030_PM_MASTER_P1_SW_EVENTS + i, 1, &value, 1);
}

#define I2C_FUEL_GAUGE					0x55
#define I2C_CHARGER					0x09

static int chk_accum_voltage(void)
{
    int error = 1;

    i2c_set_bus_num(2);

    if(!i2c_probe(I2C_FUEL_GAUGE)) {
		uchar volt1 = 0, volt2 = 0;
	        u16   voltage = 0;
	        int   i, j, t = 20000;
		const int count_try = 50;

		for(j = 0; j < count_try; j++) {
			for(i = 0; i < 3; i++) {
				if(!(error = smb_read(I2C_FUEL_GAUGE, 0x09, &volt1))) {
						voltage = (u16)(volt1 & 0xff);
		                        	voltage <<= 8;
		                        	break;
				} else
						udelay(10000 + i*10000);
				}
				
				for(i = 0; i < 3; i++) {
					if(!(error = smb_read(I2C_FUEL_GAUGE, 0x08, &volt2))) {
						voltage |= (u16)(volt2 & 0xff);
		                        	break;
					} else
						udelay(10000 + i*10000);
				}

				if(voltage < 300 || voltage > 5000) {
					if(!j)
						printf("\nWait a few seconds for battery voltage measurement...\n");

					if(j == 1) t = 150000;
					else	   t = 2000;

					while(t--) udelay(1000);
				}
				else
					break;
		}

		printf("ACCUM BATTERY VOLTAGE: %d.%03d V\n", voltage/1000, voltage%1000);

		if(voltage <= 3200) {
			if(voltage < 300) {
				printf("Too low accumulator voltage!\nUnable to boot...\n");
				goto shutdown;
			}

			if(!i2c_probe(I2C_CHARGER)) {
				for(i = 0; i < 3; i++) {
					if(!(error = smb_read(I2C_CHARGER, 0x04, &volt1)))
			                		break;
		                        else
							udelay(1000 + i * 10000);
					}

					if(!error && (volt1 & 0x80) && (volt1 & 0x40)) {
						smb_write(I2C_CHARGER, 0x02, 0xff);
						smb_write(I2C_CHARGER, 0x01, 0xaf);
						smb_write(I2C_CHARGER, 0x00, 0x61);
					} else {
							printf("Need charging!\n");
							goto shutdown;
						}
			} else {
				printf("ERROR: i2c test charge controller is failed!\n");
				error = 1;
				}
			} else
				error = 0;
		} else {
				printf("WARNING: fuel gauge is not found!\n");
				error = 0;
		}
	

	i2c_set_bus_num(0);

        return error;

shutdown:
	printf("SHUTDOWN!");
        shutdown();
}
#endif
#endif

typedef int (init_fnc_t) (void);

init_fnc_t *init_sequence[] = {
	cpu_init,		/* basic cpu dependent setup */
	board_init,		/* basic board dependent setup */
#ifdef CFG_PRINTF
 	serial_init,		/* serial communications setup */
	print_info,
#endif
	chk_accum_voltage,
	nand_init,		/* board specific nand init */
	mem_init,		/* board specific memory init */
#ifdef CONFIG_MMC
#ifdef CONFIG_DRIVER_OMAP34XX_I2C
	init_func_i2c,
#endif
#endif
  	NULL,
};

void start_armboot (void)
{
  	init_fnc_t **init_fnc_ptr;
 	int i;
	uchar *buf;

   	for (init_fnc_ptr = init_sequence; *init_fnc_ptr; ++init_fnc_ptr) {
		if ((*init_fnc_ptr)() != 0) {
			hang ();
		}
	}

	misc_init_r();
	buf =  (uchar*) CFG_LOADADDR;

	/* Always first try mmc without checking boot pins */
#if (!defined(CONFIG_OMAP3_BEAGLE) && !defined(CONFIG_O2_BOARD))
	if ((get_mem_type() == MMC_ONENAND) || (get_mem_type() == MMC_NAND))
#endif	/* CONFIG_OMAP3_BEAGLE */
		buf += mmc_boot(buf);

	if (buf == (uchar *)CFG_LOADADDR) {
		if (get_mem_type() == GPMC_NAND){
#ifdef CFG_PRINTF
			printf("Booting from nand . . .\n");
#endif
			for (i = NAND_UBOOT_START; i < NAND_UBOOT_END; i+= NAND_BLOCK_SIZE){
				if (!nand_read_block(buf, i))
					buf += NAND_BLOCK_SIZE; /* advance buf ptr */
			}
		}

		if (get_mem_type() == GPMC_ONENAND){
#ifdef CFG_PRINTF
			printf("Booting from onenand . . .\n");
#endif
			for (i = ONENAND_START_BLOCK; i < ONENAND_END_BLOCK; i++){
				if (!onenand_read_block(buf, i))
					buf += ONENAND_BLOCK_SIZE;
			}
		}
	}

#if defined (CONFIG_AM3517EVM)
	/*
	 * FIXME: Currently coping uboot image,
	 * ideally we should leverage XIP feature here
	 */
	if (get_mem_type() == GPMC_NOR) {
		int size;
		printf("Booting from NOR Flash...\n");
		size = nor_read_boot(buf);
		if (size > 0)
			buf += size;
	}
#endif

	if (buf == (uchar *)CFG_LOADADDR)
		hang();

	/* go run U-Boot and never return */
  	printf("Starting OS Bootloader...\n");
 	((init_fnc_t *)CFG_LOADADDR)();

	/* should never come here */
}

void hang (void)
{
	/* call board specific hang function */
	board_hang();

	/* if board_hang() returns, hange here */
	printf("X-Loader hangs\n");
	for (;;);
}
