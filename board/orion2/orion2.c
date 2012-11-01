/*
 * (C) Copyright 2006
 * Texas Instruments, <www.ti.com>
 * Jian Zhang <jzhang@ti.com>
 * Richard Woodruff <r-woodruff2@ti.com>
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
#include <command.h>
#include <part.h>
#include <fat.h>
#include <asm/arch/cpu.h>
#include <asm/arch/bits.h>
/*#include <asm/arch/mux.h>*/
#include <asm/arch/sys_proto.h>
#include <asm/arch/sys_info.h>
#include <asm/arch/clocks.h>
#include <asm/arch/mem.h>

/* This should be mux.h but now it's just a dirty hack for this board only*/
#ifndef _ORIONMUX_H_
#define _ORIONMUX_H_

/*
 * M0 - Mux mode 0
 * M1 - Mux mode 1
 * M2 - Mux mode 2
 * M3 - Mux mode 3
 * M4 - Mux mode 4
 * M5 - Mux mode 5
 * M6 - Mux mode 6
 * M7 - Mux mode 7
 * IDIS - Input disabled
 * IEN - Input enabled
 * PD - Active-mode pull-down enabled
 * PU - Active-mode pull-up enabled
 * PI - Active-mode pull inhibited
 * SB_LOW - Standby mode configuration: Output low-level
 * SB_HI - Standby mode configuration: Output high-level
 * SB_HIZ - Standby mode configuration: Output hi-impedence
 * SB_PD - Standby mode pull-down enabled
 * SB_PU - Standby mode pull-up enabled
 * WKEN - Wakeup input enabled
 */

#define M0 0
#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define M5 5
#define M6 6
#define M7 7
#define IDIS (0 << 8)
#define IEN (1 << 8)
#define PD (1 << 3)
#define PU (3 << 3)
#define PI (0 << 3)
#define SB_LOW (1 << 9)
#define SB_HI (5 << 9)
#define SB_HIZ (2 << 9)
#define SB_PD (1 << 12)
#define SB_PU (3 << 12)
#define WKEN (1 << 14)

/*
 * To get the physical address the offset has
 * to be added to OMAP34XX_CTRL_BASE
 */

#define CONTROL_PADCONF_GPIO_112                  0x0134
#define CONTROL_PADCONF_GPIO_113                  0x0136
#define CONTROL_PADCONF_GPIO_114                  0x0138
#define CONTROL_PADCONF_GPIO_115                  0x013A
#define CONTROL_PADCONF_GPIO_126                  0x0A54
#define CONTROL_PADCONF_GPIO_127                  0x0A56
#define CONTROL_PADCONF_GPIO_128                  0x0A58
#define CONTROL_PADCONF_GPIO_129                  0x0A5A
#define CONTROL_PADCONF_CAM_D0                    0x0116
#define CONTROL_PADCONF_CAM_D1                    0x0118
#define CONTROL_PADCONF_CAM_D2                    0x011A
#define CONTROL_PADCONF_CAM_D3                    0x011C
#define CONTROL_PADCONF_CAM_D4                    0x011E
#define CONTROL_PADCONF_CAM_D5                    0x0120
#define CONTROL_PADCONF_CAM_D6                    0x0122
#define CONTROL_PADCONF_CAM_D7                    0x0124
#define CONTROL_PADCONF_CAM_D8                    0x0126
#define CONTROL_PADCONF_CAM_D9                    0x0128
#define CONTROL_PADCONF_CAM_D10                   0x012A
#define CONTROL_PADCONF_CAM_D11                   0x012C
#define CONTROL_PADCONF_CAM_FLD                   0x0114
#define CONTROL_PADCONF_CAM_HS                    0x010C
#define CONTROL_PADCONF_CAM_PCLK                  0x0112
#define CONTROL_PADCONF_CAM_STROBE                0x0132
#define CONTROL_PADCONF_CAM_VS                    0x010E
#define CONTROL_PADCONF_CAM_WEN                   0x0130
#define CONTROL_PADCONF_CAM_XCLKA                 0x0110
#define CONTROL_PADCONF_CAM_XCLKB                 0x012E
#define CONTROL_PADCONF_DSS_ACBIAS                0x00DA
#define CONTROL_PADCONF_DSS_DATA0                 0x00DC
#define CONTROL_PADCONF_DSS_DATA1                 0x00DE
#define CONTROL_PADCONF_DSS_DATA2                 0x00E0
#define CONTROL_PADCONF_DSS_DATA3                 0x00E2
#define CONTROL_PADCONF_DSS_DATA4                 0x00E4
#define CONTROL_PADCONF_DSS_DATA5                 0x00E6
#define CONTROL_PADCONF_DSS_DATA6                 0x00E8
#define CONTROL_PADCONF_DSS_DATA7                 0x00EA
#define CONTROL_PADCONF_DSS_DATA8                 0x00EC
#define CONTROL_PADCONF_DSS_DATA9                 0x00EE
#define CONTROL_PADCONF_DSS_DATA10                0x00F0
#define CONTROL_PADCONF_DSS_DATA11                0x00F2
#define CONTROL_PADCONF_DSS_DATA12                0x00F4
#define CONTROL_PADCONF_DSS_DATA13                0x00F6
#define CONTROL_PADCONF_DSS_DATA14                0x00F8
#define CONTROL_PADCONF_DSS_DATA15                0x00FA
#define CONTROL_PADCONF_DSS_DATA16                0x00FC
#define CONTROL_PADCONF_DSS_DATA17                0x00FE
#define CONTROL_PADCONF_DSS_DATA18                0x0100
#define CONTROL_PADCONF_DSS_DATA19                0x0102
#define CONTROL_PADCONF_DSS_DATA20                0x0104
#define CONTROL_PADCONF_DSS_DATA21                0x0106
#define CONTROL_PADCONF_DSS_DATA22                0x0108
#define CONTROL_PADCONF_DSS_DATA23                0x010A
#define CONTROL_PADCONF_DSS_HSYNC                 0x00D6
#define CONTROL_PADCONF_DSS_PCLK                  0x00D4
#define CONTROL_PADCONF_DSS_VSYNC                 0x00D8
#define CONTROL_PADCONF_ETK_CLK_ES2               0x05D8
#define CONTROL_PADCONF_ETK_CTL_ES2               0x05DA
#define CONTROL_PADCONF_ETK_D0_ES2                0x05DC
#define CONTROL_PADCONF_ETK_D1_ES2                0x05DE
#define CONTROL_PADCONF_ETK_D2_ES2                0x05E0
#define CONTROL_PADCONF_ETK_D3_ES2                0x05E2
#define CONTROL_PADCONF_ETK_D4_ES2                0x05E4
#define CONTROL_PADCONF_ETK_D5_ES2                0x05E6
#define CONTROL_PADCONF_ETK_D6_ES2                0x05E8
#define CONTROL_PADCONF_ETK_D7_ES2                0x05EA
#define CONTROL_PADCONF_ETK_D8_ES2                0x05EC
#define CONTROL_PADCONF_ETK_D9_ES2                0x05EE
#define CONTROL_PADCONF_ETK_D10_ES2               0x05F0
#define CONTROL_PADCONF_ETK_D11_ES2               0x05F2
#define CONTROL_PADCONF_ETK_D12_ES2               0x05F4
#define CONTROL_PADCONF_ETK_D13_ES2               0x05F6
#define CONTROL_PADCONF_ETK_D14_ES2               0x05F8
#define CONTROL_PADCONF_ETK_D15_ES2               0x05FA
#define CONTROL_PADCONF_GPMC_A1                   0x007A
#define CONTROL_PADCONF_GPMC_A2                   0x007C
#define CONTROL_PADCONF_GPMC_A3                   0x007E
#define CONTROL_PADCONF_GPMC_A4                   0x0080
#define CONTROL_PADCONF_GPMC_A5                   0x0082
#define CONTROL_PADCONF_GPMC_A6                   0x0084
#define CONTROL_PADCONF_GPMC_A7                   0x0086
#define CONTROL_PADCONF_GPMC_A8                   0x0088
#define CONTROL_PADCONF_GPMC_A9                   0x008A
#define CONTROL_PADCONF_GPMC_A10                  0x008C
#define CONTROL_PADCONF_GPMC_A11                  0x0264
#define CONTROL_PADCONF_GPMC_CLK                  0x00BE
#define CONTROL_PADCONF_GPMC_D0                   0x008E
#define CONTROL_PADCONF_GPMC_D1                   0x0090
#define CONTROL_PADCONF_GPMC_D2                   0x0092
#define CONTROL_PADCONF_GPMC_D3                   0x0094
#define CONTROL_PADCONF_GPMC_D4                   0x0096
#define CONTROL_PADCONF_GPMC_D5                   0x0098
#define CONTROL_PADCONF_GPMC_D6                   0x009A
#define CONTROL_PADCONF_GPMC_D7                   0x009C
#define CONTROL_PADCONF_GPMC_D8                   0x009E
#define CONTROL_PADCONF_GPMC_D9                   0x00A0
#define CONTROL_PADCONF_GPMC_D10                  0x00A2
#define CONTROL_PADCONF_GPMC_D11                  0x00A4
#define CONTROL_PADCONF_GPMC_D12                  0x00A6
#define CONTROL_PADCONF_GPMC_D13                  0x00A8
#define CONTROL_PADCONF_GPMC_D14                  0x00AA
#define CONTROL_PADCONF_GPMC_D15                  0x00AC
#define CONTROL_PADCONF_GPMC_NADV_ALE             0x00C0
#define CONTROL_PADCONF_GPMC_NBE0_CLE             0x00C6
#define CONTROL_PADCONF_GPMC_NBE1                 0x00C8
#define CONTROL_PADCONF_GPMC_NCS0                 0x00AE
#define CONTROL_PADCONF_GPMC_NCS1                 0x00B0
#define CONTROL_PADCONF_GPMC_NCS2                 0x00B2
#define CONTROL_PADCONF_GPMC_NCS3                 0x00B4
#define CONTROL_PADCONF_GPMC_NCS4                 0x00B6
#define CONTROL_PADCONF_GPMC_NCS5                 0x00B8
#define CONTROL_PADCONF_GPMC_NCS6                 0x00BA
#define CONTROL_PADCONF_GPMC_NCS7                 0x00BC
#define CONTROL_PADCONF_GPMC_NOE                  0x00C2
#define CONTROL_PADCONF_GPMC_NWE                  0x00C4
#define CONTROL_PADCONF_GPMC_NWP                  0x00CA
#define CONTROL_PADCONF_GPMC_WAIT0                0x00CC
#define CONTROL_PADCONF_GPMC_WAIT1                0x00CE
#define CONTROL_PADCONF_GPMC_WAIT2                0x00D0
#define CONTROL_PADCONF_GPMC_WAIT3                0x00D2
#define CONTROL_PADCONF_HDQ_SIO                   0x01C6
#define CONTROL_PADCONF_HSUSB0_CLK                0x01A2
#define CONTROL_PADCONF_HSUSB0_DATA0              0x01AA
#define CONTROL_PADCONF_HSUSB0_DATA1              0x01AC
#define CONTROL_PADCONF_HSUSB0_DATA2              0x01AE
#define CONTROL_PADCONF_HSUSB0_DATA3              0x01B0
#define CONTROL_PADCONF_HSUSB0_DATA4              0x01B2
#define CONTROL_PADCONF_HSUSB0_DATA5              0x01B4
#define CONTROL_PADCONF_HSUSB0_DATA6              0x01B6
#define CONTROL_PADCONF_HSUSB0_DATA7              0x01B8
#define CONTROL_PADCONF_HSUSB0_DIR                0x01A6
#define CONTROL_PADCONF_HSUSB0_NXT                0x01A8
#define CONTROL_PADCONF_HSUSB0_STP                0x01A4
#define CONTROL_PADCONF_I2C1_SCL                  0x01BA
#define CONTROL_PADCONF_I2C1_SDA                  0x01BC
#define CONTROL_PADCONF_I2C2_SCL                  0x01BE
#define CONTROL_PADCONF_I2C2_SDA                  0x01C0
#define CONTROL_PADCONF_I2C3_SCL                  0x01C2
#define CONTROL_PADCONF_I2C3_SDA                  0x01C4
#define CONTROL_PADCONF_I2C4_SCL                  0x0A00
#define CONTROL_PADCONF_I2C4_SDA                  0x0A02
#define CONTROL_PADCONF_JTAG_EMU0                 0x0A24
#define CONTROL_PADCONF_JTAG_EMU1                 0x0A26
#define CONTROL_PADCONF_JTAG_NTRST                0x0A1C
#define CONTROL_PADCONF_JTAG_RTCK                 0x0A4E
#define CONTROL_PADCONF_JTAG_TCK                  0x0A1E
#define CONTROL_PADCONF_JTAG_TDI                  0x0A22
#define CONTROL_PADCONF_JTAG_TDO                  0x0A50
#define CONTROL_PADCONF_JTAG_TMS                  0x0A20
#define CONTROL_PADCONF_MCBSP_CLKS                0x0194
#define CONTROL_PADCONF_MCBSP1_CLKR               0x018C
#define CONTROL_PADCONF_MCBSP1_CLKX               0x0198
#define CONTROL_PADCONF_MCBSP1_DR                 0x0192
#define CONTROL_PADCONF_MCBSP1_DX                 0x0190
#define CONTROL_PADCONF_MCBSP1_FSR                0x018E
#define CONTROL_PADCONF_MCBSP1_FSX                0x0196
#define CONTROL_PADCONF_MCBSP2_CLKX               0x013E
#define CONTROL_PADCONF_MCBSP2_DR                 0x0140
#define CONTROL_PADCONF_MCBSP2_DX                 0x0142
#define CONTROL_PADCONF_MCBSP2_FSX                0x013C
#define CONTROL_PADCONF_MCBSP3_CLKX               0x0170
#define CONTROL_PADCONF_MCBSP3_DR                 0x016E
#define CONTROL_PADCONF_MCBSP3_DX                 0x016C
#define CONTROL_PADCONF_MCBSP3_FSX                0x0172
#define CONTROL_PADCONF_MCBSP4_CLKX               0x0184
#define CONTROL_PADCONF_MCBSP4_DR                 0x0186
#define CONTROL_PADCONF_MCBSP4_DX                 0x0188
#define CONTROL_PADCONF_MCBSP4_FSX                0x018A
#define CONTROL_PADCONF_MCSPI1_CLK                0x01C8
#define CONTROL_PADCONF_MCSPI1_CS0                0x01CE
#define CONTROL_PADCONF_MCSPI1_CS1                0x01D0
#define CONTROL_PADCONF_MCSPI1_CS2                0x01D2
#define CONTROL_PADCONF_MCSPI1_CS3                0x01D4
#define CONTROL_PADCONF_MCSPI1_SIMO               0x01CA
#define CONTROL_PADCONF_MCSPI1_SOMI               0x01CC
#define CONTROL_PADCONF_MCSPI2_CLK                0x01D6
#define CONTROL_PADCONF_MCSPI2_CS0                0x01DC
#define CONTROL_PADCONF_MCSPI2_CS1                0x01DE
#define CONTROL_PADCONF_MCSPI2_SIMO               0x01D8
#define CONTROL_PADCONF_MCSPI2_SOMI               0x01DA
#define CONTROL_PADCONF_MMC1_CLK                  0x0144
#define CONTROL_PADCONF_MMC1_CMD                  0x0146
#define CONTROL_PADCONF_MMC1_DAT0                 0x0148
#define CONTROL_PADCONF_MMC1_DAT1                 0x014A
#define CONTROL_PADCONF_MMC1_DAT2                 0x014C
#define CONTROL_PADCONF_MMC1_DAT3                 0x014E
#define CONTROL_PADCONF_MMC2_CLK                  0x0158
#define CONTROL_PADCONF_MMC2_CMD                  0x015A
#define CONTROL_PADCONF_MMC2_DAT0                 0x015C
#define CONTROL_PADCONF_MMC2_DAT1                 0x015E
#define CONTROL_PADCONF_MMC2_DAT2                 0x0160
#define CONTROL_PADCONF_MMC2_DAT3                 0x0162
#define CONTROL_PADCONF_MMC2_DAT4                 0x0164
#define CONTROL_PADCONF_MMC2_DAT5                 0x0166
#define CONTROL_PADCONF_MMC2_DAT6                 0x0168
#define CONTROL_PADCONF_MMC2_DAT7                 0x016A
#define CONTROL_PADCONF_SDRC_A0                   0x05A4
#define CONTROL_PADCONF_SDRC_A1                   0x05A6
#define CONTROL_PADCONF_SDRC_A2                   0x05A8
#define CONTROL_PADCONF_SDRC_A3                   0x05AA
#define CONTROL_PADCONF_SDRC_A4                   0x05AC
#define CONTROL_PADCONF_SDRC_A5                   0x05AE
#define CONTROL_PADCONF_SDRC_A6                   0x05B0
#define CONTROL_PADCONF_SDRC_A7                   0x05B2
#define CONTROL_PADCONF_SDRC_A8                   0x05B4
#define CONTROL_PADCONF_SDRC_A9                   0x05B6
#define CONTROL_PADCONF_SDRC_A10                  0x05B8
#define CONTROL_PADCONF_SDRC_A11                  0x05BA
#define CONTROL_PADCONF_SDRC_A12                  0x05BC
#define CONTROL_PADCONF_SDRC_A13                  0x05BE
#define CONTROL_PADCONF_SDRC_A14                  0x05C0
#define CONTROL_PADCONF_SDRC_BA0                  0x05A0
#define CONTROL_PADCONF_SDRC_BA1                  0x05A2
#define CONTROL_PADCONF_SDRC_CKE0                 0x0262
#define CONTROL_PADCONF_SDRC_CKE1                 0x0264
#define CONTROL_PADCONF_SDRC_CLK                  0x0070
#define CONTROL_PADCONF_SDRC_D0                   0x0030
#define CONTROL_PADCONF_SDRC_D1                   0x0032
#define CONTROL_PADCONF_SDRC_D2                   0x0034
#define CONTROL_PADCONF_SDRC_D3                   0x0036
#define CONTROL_PADCONF_SDRC_D4                   0x0038
#define CONTROL_PADCONF_SDRC_D5                   0x003A
#define CONTROL_PADCONF_SDRC_D6                   0x003C
#define CONTROL_PADCONF_SDRC_D7                   0x003E
#define CONTROL_PADCONF_SDRC_D8                   0x0040
#define CONTROL_PADCONF_SDRC_D9                   0x0042
#define CONTROL_PADCONF_SDRC_D10                  0x0044
#define CONTROL_PADCONF_SDRC_D11                  0x0046
#define CONTROL_PADCONF_SDRC_D12                  0x0048
#define CONTROL_PADCONF_SDRC_D13                  0x004A
#define CONTROL_PADCONF_SDRC_D14                  0x004C
#define CONTROL_PADCONF_SDRC_D15                  0x004E
#define CONTROL_PADCONF_SDRC_D16                  0x0050
#define CONTROL_PADCONF_SDRC_D17                  0x0052
#define CONTROL_PADCONF_SDRC_D18                  0x0054
#define CONTROL_PADCONF_SDRC_D19                  0x0056
#define CONTROL_PADCONF_SDRC_D20                  0x0058
#define CONTROL_PADCONF_SDRC_D21                  0x005A
#define CONTROL_PADCONF_SDRC_D22                  0x005C
#define CONTROL_PADCONF_SDRC_D23                  0x005E
#define CONTROL_PADCONF_SDRC_D24                  0x0060
#define CONTROL_PADCONF_SDRC_D25                  0x0062
#define CONTROL_PADCONF_SDRC_D26                  0x0064
#define CONTROL_PADCONF_SDRC_D27                  0x0066
#define CONTROL_PADCONF_SDRC_D28                  0x0068
#define CONTROL_PADCONF_SDRC_D29                  0x006A
#define CONTROL_PADCONF_SDRC_D30                  0x006C
#define CONTROL_PADCONF_SDRC_D31                  0x006E
#define CONTROL_PADCONF_SDRC_DM0                  0x05CE
#define CONTROL_PADCONF_SDRC_DM1                  0x05D0
#define CONTROL_PADCONF_SDRC_DM2                  0x05D2
#define CONTROL_PADCONF_SDRC_DM3                  0x05D4
#define CONTROL_PADCONF_SDRC_DQS0                 0x0072
#define CONTROL_PADCONF_SDRC_DQS1                 0x0074
#define CONTROL_PADCONF_SDRC_DQS2                 0x0076
#define CONTROL_PADCONF_SDRC_DQS3                 0x0078
#define CONTROL_PADCONF_SDRC_NCAS                 0x05CA
#define CONTROL_PADCONF_SDRC_NCLK                 0x05C6
#define CONTROL_PADCONF_SDRC_NCS0                 0x05C2
#define CONTROL_PADCONF_SDRC_NCS1                 0x05C4
#define CONTROL_PADCONF_SDRC_NRAS                 0x05C8
#define CONTROL_PADCONF_SDRC_NWE                  0x05CC
#define CONTROL_PADCONF_SYS_32K                   0x0A04
#define CONTROL_PADCONF_SYS_BOOT0                 0x0A0A
#define CONTROL_PADCONF_SYS_BOOT1                 0x0A0C
#define CONTROL_PADCONF_SYS_BOOT2                 0x0A0E
#define CONTROL_PADCONF_SYS_BOOT3                 0x0A10
#define CONTROL_PADCONF_SYS_BOOT4                 0x0A12
#define CONTROL_PADCONF_SYS_BOOT5                 0x0A14
#define CONTROL_PADCONF_SYS_BOOT6                 0x0A16
#define CONTROL_PADCONF_SYS_CLKOUT1               0x0A1A
#define CONTROL_PADCONF_SYS_CLKOUT2               0x01E2
#define CONTROL_PADCONF_SYS_CLKREQ                0x0A06
#define CONTROL_PADCONF_SYS_NIRQ                  0x01E0
#define CONTROL_PADCONF_SYS_NRESWARM              0x0A08
#define CONTROL_PADCONF_SYS_OFF_MODE              0x0A18
#define CONTROL_PADCONF_UART1_CTS                 0x0180
#define CONTROL_PADCONF_UART1_RTS                 0x017E
#define CONTROL_PADCONF_UART1_RX                  0x0182
#define CONTROL_PADCONF_UART1_TX                  0x017C
#define CONTROL_PADCONF_UART2_CTS                 0x0174
#define CONTROL_PADCONF_UART2_RTS                 0x0176
#define CONTROL_PADCONF_UART2_RX                  0x017A
#define CONTROL_PADCONF_UART2_TX                  0x0178
#define CONTROL_PADCONF_UART3_CTS_RCTX            0x019A
#define CONTROL_PADCONF_UART3_RTS_SD              0x019C
#define CONTROL_PADCONF_UART3_RX_IRRX             0x019E
#define CONTROL_PADCONF_UART3_TX_IRTX             0x01A0

#endif


/* Used to index into DPLL parameter tables */
struct dpll_param {
        unsigned int m;
        unsigned int n;
        unsigned int fsel;
        unsigned int m2;
};

struct dpll_per_36x_param {
	unsigned int sys_clk;
	unsigned int m;
	unsigned int n;
	unsigned int m2;
	unsigned int m3;
	unsigned int m4;
	unsigned int m5;
	unsigned int m6;
	unsigned int m2div;
};

typedef struct dpll_param dpll_param;

extern unsigned int is_ddr_166M;

#define MAX_SIL_INDEX	3

/* Following functions are exported from lowlevel_init.S */
extern dpll_param *get_mpu_dpll_param(void);
extern dpll_param *get_iva_dpll_param(void);
extern dpll_param *get_core_dpll_param(void);
extern dpll_param *get_per_dpll_param(void);

extern dpll_param *get_36x_mpu_dpll_param(void);
extern dpll_param *get_36x_iva_dpll_param(void);
extern dpll_param *get_36x_core_dpll_param(void);
extern dpll_param *get_36x_per_dpll_param(void);

extern int mmc_init(int verbose);
extern block_dev_desc_t *mmc_get_dev(int dev);

#define __raw_readl(a)    (*(volatile unsigned int *)(a))
#define __raw_writel(v,a) (*(volatile unsigned int *)(a) = (v))
#define __raw_readw(a)    (*(volatile unsigned short *)(a))
#define __raw_writew(v,a) (*(volatile unsigned short *)(a) = (v))

/*******************************************************
 * Routine: delay
 * Description: spinning delay to use before udelay works
 ******************************************************/
static inline void delay(unsigned long loops)
{
	__asm__ volatile ("1:\n" "subs %0, %1, #1\n"
			  "bne 1b":"=r" (loops):"0"(loops));
}

void udelay (unsigned long usecs) {
	delay(usecs);
}

/*****************************************
 * Routine: board_init
 * Description: Early hardware init.
 *****************************************/
int board_init (void)
{
	return 0;
}

/*************************************************************
 *  get_device_type(): tell if GP/HS/EMU/TST
 *************************************************************/
u32 get_device_type(void)
{
        int mode;
        mode = __raw_readl(CONTROL_STATUS) & (DEVICE_MASK);
        return(mode >>= 8);
}

/************************************************
 * get_sysboot_value(void) - return SYS_BOOT[4:0]
 ************************************************/
u32 get_sysboot_value(void)
{
        int mode;
        mode = __raw_readl(CONTROL_STATUS) & (SYSBOOT_MASK);
        return mode;
}
/*************************************************************
 * Routine: get_mem_type(void) - returns the kind of memory connected
 * to GPMC that we are trying to boot form. Uses SYS BOOT settings.
 *************************************************************/
u32 get_mem_type(void)
{
        u32   mem_type = get_sysboot_value();
        switch (mem_type){
            case 0:
            case 2:
            case 4:
            case 16:
            case 22:    return GPMC_ONENAND;

            case 1:
            case 12:
            case 15:
            case 21:
            case 27:    return GPMC_NAND;

            case 3:
            case 6:     return MMC_ONENAND;

            case 8:
            case 11:
            case 14:
            case 20:
            case 26:    return GPMC_MDOC;

            case 17:
            case 18:
            case 24:	return MMC_NAND;

            case 7:
            case 10:
            case 13:
            case 19:
            case 25:
            default:    return GPMC_NOR;
        }
}

/******************************************
 * get_cpu_rev(void) - extract version info
 ******************************************/
u32 get_cpu_rev(void)
{
	u32 cpuid=0;
	/* On ES1.0 the IDCODE register is not exposed on L4
	 * so using CPU ID to differentiate
	 * between ES2.0 and ES1.0.
	 */
	__asm__ __volatile__("mrc p15, 0, %0, c0, c0, 0":"=r" (cpuid));
	if((cpuid  & 0xf) == 0x0)
		return CPU_3430_ES1;
	else
		return CPU_3430_ES2;

}

u32 is_cpu_family(void)
{
	u32 cpuid = 0, cpu_family = 0;
	u16 hawkeye;

	__asm__ __volatile__("mrc p15, 0, %0, c0, c0, 0":"=r"(cpuid));
	if ((cpuid & 0xf) == 0x0) {
		cpu_family = CPU_OMAP34XX;
	} else {
		cpuid = __raw_readl(OMAP34XX_CONTROL_ID);
		hawkeye  = (cpuid >> HAWKEYE_SHIFT) & 0xffff;

		switch (hawkeye) {
			case HAWKEYE_OMAP34XX:
				cpu_family = CPU_OMAP34XX;
				break;
			case HAWKEYE_AM35XX:
				cpu_family = CPU_AM35XX;
				break;
			case HAWKEYE_OMAP36XX:
				cpu_family = CPU_OMAP36XX;
				break;
			default:
				cpu_family = CPU_OMAP34XX;
				break;
		}
	}
	return cpu_family;
}
/******************************************
 * cpu_is_3410(void) - returns true for 3410
 ******************************************/
u32 cpu_is_3410(void)
{
	int status;
	if(get_cpu_rev() < CPU_3430_ES2) {
		return 0;
	} else {
		/* read scalability status and return 1 for 3410*/
		status = __raw_readl(CONTROL_SCALABLE_OMAP_STATUS);
		/* Check whether MPU frequency is set to 266 MHz which
		 * is nominal for 3410. If yes return true else false
		 */
		if (((status >> 8) & 0x3) == 0x2)
			return 1;
		else
			return 0;
	}
}

/*****************************************************************
 * sr32 - clear & set a value in a bit range for a 32 bit address
 *****************************************************************/
void sr32(u32 addr, u32 start_bit, u32 num_bits, u32 value)
{
	u32 tmp, msk = 0;
	msk = 1 << num_bits;
	--msk;
	tmp = __raw_readl(addr) & ~(msk << start_bit);
	tmp |=  value << start_bit;
	__raw_writel(tmp, addr);
}

/*********************************************************************
 * wait_on_value() - common routine to allow waiting for changes in
 *   volatile regs.
 *********************************************************************/
u32 wait_on_value(u32 read_bit_mask, u32 match_value, u32 read_addr, u32 bound)
{
	u32 i = 0, val;
	do {
		++i;
		val = __raw_readl(read_addr) & read_bit_mask;
		if (val == match_value)
			return (1);
		if (i == bound)
			return (0);
	} while (1);
}

#ifdef CFG_OMAPEVM_DDR
/*********************************************************************
 * sdrc_init() - Configure SDRC
 * with help from
 * http://processors.wiki.ti.com/index.php/Setting_up_OMAP35x_SDRC_registers
 *********************************************************************/
void sdrc_init(void)
{
	/* reset sdrc controller */
	__raw_writel(SOFTRESET, SDRC_SYSCONFIG);
	wait_on_value(BIT0, BIT0, SDRC_STATUS, 12000000);
	__raw_writel(0, SDRC_SYSCONFIG);

	/* setup sdrc to ball mux */
	__raw_writel(SDP_SDRC_SHARING, SDRC_SHARING);

	/* set mdcfg */
	__raw_writel(SDP_SDRC_MDCFG_0_DDR_MICRON_XM, SDRC_MCFG_0);
	__raw_writel(MICRON_V_ACTIMA_200_H64M32, SDRC_ACTIM_CTRLA_0);
	__raw_writel(MICRON_V_ACTIMB_200_H64M32, SDRC_ACTIM_CTRLB_0);
	__raw_writel(SDRC_RFR_CTRL_200_H64M32, SDRC_RFR_CTRL_0);

	__raw_writel(SDP_SDRC_POWER_POP, SDRC_POWER);

	/* init sequence for mDDR/mSDR using manual commands (DDR is different) */
	__raw_writel(CMD_NOP, SDRC_MANUAL_0);
	delay(5000);
	__raw_writel(CMD_PRECHARGE, SDRC_MANUAL_0);
	__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_0);
	__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_0);

	/* set mr0 */
	__raw_writel(SDP_SDRC_MR_0_DDR, SDRC_MR_0);

	/* set up dll */
	__raw_writel(SDP_SDRC_DLLAB_CTRL, SDRC_DLLA_CTRL);
	delay(0x2000);	/* give time to lock */

}
#endif /* CFG_OMAPEVM_DDR */

/*************************************************************
 * get_sys_clk_speed - determine reference oscillator speed
 *  based on known 32kHz clock and gptimer.
 *************************************************************/
u32 get_osc_clk_speed(void)
{
	u32 start, cstart, cend, cdiff, cdiv, val;

	val = __raw_readl(PRM_CLKSRC_CTRL);

	if (val & BIT7)
		cdiv = 2;
	else if (val & BIT6)
		cdiv = 1;
	else
		/*
		 * Should never reach here!
		 * TBD: Add a WARN()/BUG()
		 *      For now, assume divider as 1.
		 */
		cdiv = 1;

	/* enable timer2 */
	val = __raw_readl(CM_CLKSEL_WKUP) | BIT0;
	__raw_writel(val, CM_CLKSEL_WKUP);	/* select sys_clk for GPT1 */

	/* Enable I and F Clocks for GPT1 */
	val = __raw_readl(CM_ICLKEN_WKUP) | BIT0 | BIT2;
	__raw_writel(val, CM_ICLKEN_WKUP);
	val = __raw_readl(CM_FCLKEN_WKUP) | BIT0;
	__raw_writel(val, CM_FCLKEN_WKUP);

	__raw_writel(0, OMAP34XX_GPT1 + TLDR);	/* start counting at 0 */
	__raw_writel(GPT_EN, OMAP34XX_GPT1 + TCLR);     /* enable clock */
	/* enable 32kHz source *//* enabled out of reset */
	/* determine sys_clk via gauging */

	start = 20 + __raw_readl(S32K_CR);	/* start time in 20 cycles */
	while (__raw_readl(S32K_CR) < start);	/* dead loop till start time */
	cstart = __raw_readl(OMAP34XX_GPT1 + TCRR);	/* get start sys_clk count */
	while (__raw_readl(S32K_CR) < (start + 20));	/* wait for 40 cycles */
	cend = __raw_readl(OMAP34XX_GPT1 + TCRR);	/* get end sys_clk count */
	cdiff = cend - cstart;				/* get elapsed ticks */

	if (cdiv == 2)
	{
		cdiff *= 2;
	}

	/* based on number of ticks assign speed */
	if (cdiff > 19000)
		return (S38_4M);
	else if (cdiff > 15200)
		return (S26M);
	else if (cdiff > 13000)
		return (S24M);
	else if (cdiff > 9000)
		return (S19_2M);
	else if (cdiff > 7600)
		return (S13M);
	else
		return (S12M);
}

/******************************************************************************
 * get_sys_clkin_sel() - returns the sys_clkin_sel field value based on
 *   -- input oscillator clock frequency.
 *
 *****************************************************************************/
void get_sys_clkin_sel(u32 osc_clk, u32 *sys_clkin_sel)
{
	if(osc_clk == S38_4M)
		*sys_clkin_sel=  4;
	else if(osc_clk == S26M)
		*sys_clkin_sel = 3;
	else if(osc_clk == S19_2M)
		*sys_clkin_sel = 2;
	else if(osc_clk == S13M)
		*sys_clkin_sel = 1;
	else if(osc_clk == S12M)
		*sys_clkin_sel = 0;
}

/*
 * OMAP34x/35x specific functions
 */
static void dpll3_init_34xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address of Core DPLL param table*/
	ptr = (dpll_param *)get_core_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr = ptr + 2*clk_index + sil_index;

	/* CORE DPLL */
	/* Select relock bypass: CM_CLKEN_PLL[0:2] */
	sr32(CM_CLKEN_PLL, 0, 3, PLL_FAST_RELOCK_BYPASS);
	wait_on_value(BIT0, 0, CM_IDLEST_CKGEN, LDELAY);

	/* CM_CLKSEL1_EMU[DIV_DPLL3] */
	sr32(CM_CLKSEL1_EMU, 16, 5, CORE_M3X2);

	/* M2 (CORE_DPLL_CLKOUT_DIV): CM_CLKSEL1_PLL[27:31] */
	sr32(CM_CLKSEL1_PLL, 27, 5, ptr->m2);

	/* M (CORE_DPLL_MULT): CM_CLKSEL1_PLL[16:26] */
	sr32(CM_CLKSEL1_PLL, 16, 11, ptr->m);

	/* N (CORE_DPLL_DIV): CM_CLKSEL1_PLL[8:14] */
	sr32(CM_CLKSEL1_PLL, 8, 7, ptr->n);

	/* Source is the CM_96M_FCLK: CM_CLKSEL1_PLL[6] */
	sr32(CM_CLKSEL1_PLL, 6, 1, 0);

	sr32(CM_CLKSEL_CORE, 8, 4, CORE_SSI_DIV);	/* ssi */
	sr32(CM_CLKSEL_CORE, 4, 2, CORE_FUSB_DIV);	/* fsusb */
	sr32(CM_CLKSEL_CORE, 2, 2, CORE_L4_DIV);	/* l4 */
	sr32(CM_CLKSEL_CORE, 0, 2, CORE_L3_DIV);	/* l3 */

	sr32(CM_CLKSEL_GFX,  0, 3, GFX_DIV_34X);	/* gfx */
	sr32(CM_CLKSEL_WKUP, 1, 2, WKUP_RSM);		/* reset mgr */

	/* FREQSEL (CORE_DPLL_FREQSEL): CM_CLKEN_PLL[4:7] */
	sr32(CM_CLKEN_PLL,   4, 4, ptr->fsel);
	sr32(CM_CLKEN_PLL,   0, 3, PLL_LOCK);		/* lock mode */

	wait_on_value(BIT0, 1, CM_IDLEST_CKGEN, LDELAY);
}

static void dpll4_init_34xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	ptr = (dpll_param *)get_per_dpll_param();

	/* Moving it to the right sysclk base */
	ptr = ptr + clk_index;

	/* EN_PERIPH_DPLL: CM_CLKEN_PLL[16:18] */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_STOP);
	wait_on_value(BIT1, 0, CM_IDLEST_CKGEN, LDELAY);

	sr32(CM_CLKSEL1_EMU, 24, 5, PER_M6X2);		/* set M6 */
	sr32(CM_CLKSEL_CAM, 0, 5, PER_M5X2);		/* set M5 */
	sr32(CM_CLKSEL_DSS, 0, 5, PER_M4X2);		/* set M4 */
	sr32(CM_CLKSEL_DSS, 8, 5, PER_M3X2);		/* set M3 */

	/* M2 (DIV_96M): CM_CLKSEL3_PLL[0:4] */
	sr32(CM_CLKSEL3_PLL, 0, 5, ptr->m2);

	/* M (PERIPH_DPLL_MULT): CM_CLKSEL2_PLL[8:18] */
	sr32(CM_CLKSEL2_PLL, 8, 11, ptr->m);

	/* N (PERIPH_DPLL_DIV): CM_CLKSEL2_PLL[0:6] */
	sr32(CM_CLKSEL2_PLL, 0, 7, ptr->n);

	/* FREQSEL (PERIPH_DPLL_FREQSEL): CM_CLKEN_PLL[20:23] */
	sr32(CM_CLKEN_PLL, 20, 4, ptr->fsel);

	/* LOCK MODE (EN_PERIPH_DPLL) : CM_CLKEN_PLL[16:18] */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_LOCK);
	wait_on_value(BIT1, 2, CM_IDLEST_CKGEN, LDELAY);
}

static void mpu_init_34xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address to MPU DPLL param table*/
	ptr = (dpll_param *)get_mpu_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr = ptr + 2*clk_index + sil_index;

	/* MPU DPLL (unlocked already) */
	/* M2 (MPU_DPLL_CLKOUT_DIV) : CM_CLKSEL2_PLL_MPU[0:4] */
	sr32(CM_CLKSEL2_PLL_MPU, 0, 5, ptr->m2);

	/* M (MPU_DPLL_MULT) : CM_CLKSEL2_PLL_MPU[8:18] */
	sr32(CM_CLKSEL1_PLL_MPU, 8, 11, ptr->m);

	/* N (MPU_DPLL_DIV) : CM_CLKSEL2_PLL_MPU[0:6] */
	sr32(CM_CLKSEL1_PLL_MPU, 0, 7, ptr->n);

	/* FREQSEL (MPU_DPLL_FREQSEL) : CM_CLKEN_PLL_MPU[4:7] */
	sr32(CM_CLKEN_PLL_MPU, 4, 4, ptr->fsel);
}

static void iva_init_34xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address to IVA DPLL param table*/
	ptr = (dpll_param *)get_iva_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr = ptr + 2*clk_index + sil_index;

	/* IVA DPLL */
	/* EN_IVA2_DPLL : CM_CLKEN_PLL_IVA2[0:2] */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_STOP);
	wait_on_value(BIT0, 0, CM_IDLEST_PLL_IVA2, LDELAY);

	/* M2 (IVA2_DPLL_CLKOUT_DIV) : CM_CLKSEL2_PLL_IVA2[0:4] */
	sr32(CM_CLKSEL2_PLL_IVA2, 0, 5, ptr->m2);

	/* M (IVA2_DPLL_MULT) : CM_CLKSEL1_PLL_IVA2[8:18] */
	sr32(CM_CLKSEL1_PLL_IVA2, 8, 11, ptr->m);

	/* N (IVA2_DPLL_DIV) : CM_CLKSEL1_PLL_IVA2[0:6] */
	sr32(CM_CLKSEL1_PLL_IVA2, 0, 7, ptr->n);

	/* FREQSEL (IVA2_DPLL_FREQSEL) : CM_CLKEN_PLL_IVA2[4:7] */
	sr32(CM_CLKEN_PLL_IVA2, 4, 4, ptr->fsel);

	/* LOCK MODE (EN_IVA2_DPLL) : CM_CLKEN_PLL_IVA2[0:2] */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_LOCK);

	wait_on_value(BIT0, 1, CM_IDLEST_PLL_IVA2, LDELAY);
}

/*
 * OMAP3630 specific functions
 */
static void dpll3_init_36xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address of Core DPLL param table*/
	ptr = (dpll_param *)get_36x_core_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr += clk_index;

	/* CORE DPLL */
	/* Select relock bypass: CM_CLKEN_PLL[0:2] */
	sr32(CM_CLKEN_PLL, 0, 3, PLL_FAST_RELOCK_BYPASS);
	wait_on_value(BIT0, 0, CM_IDLEST_CKGEN, LDELAY);

	/* CM_CLKSEL1_EMU[DIV_DPLL3] */
	sr32(CM_CLKSEL1_EMU, 16, 5, CORE_M3X2);

	/* M2 (CORE_DPLL_CLKOUT_DIV): CM_CLKSEL1_PLL[27:31] */
	sr32(CM_CLKSEL1_PLL, 27, 5, ptr->m2);

	/* M (CORE_DPLL_MULT): CM_CLKSEL1_PLL[16:26] */
	sr32(CM_CLKSEL1_PLL, 16, 11, ptr->m);

	/* N (CORE_DPLL_DIV): CM_CLKSEL1_PLL[8:14] */
	sr32(CM_CLKSEL1_PLL, 8, 7, ptr->n);

	/* Source is the CM_96M_FCLK: CM_CLKSEL1_PLL[6] */
	sr32(CM_CLKSEL1_PLL, 6, 1, 0);

	sr32(CM_CLKSEL_CORE, 8, 4, CORE_SSI_DIV);	/* ssi */
	sr32(CM_CLKSEL_CORE, 4, 2, CORE_FUSB_DIV);	/* fsusb */
	sr32(CM_CLKSEL_CORE, 2, 2, CORE_L4_DIV);	/* l4 */
	sr32(CM_CLKSEL_CORE, 0, 2, CORE_L3_DIV);	/* l3 */

	sr32(CM_CLKSEL_GFX,  0, 3, GFX_DIV_36X);		/* gfx */
	sr32(CM_CLKSEL_WKUP, 1, 2, WKUP_RSM);		/* reset mgr */

	/* FREQSEL (CORE_DPLL_FREQSEL): CM_CLKEN_PLL[4:7] */
	sr32(CM_CLKEN_PLL,   4, 4, ptr->fsel);
	sr32(CM_CLKEN_PLL,   0, 3, PLL_LOCK);		/* lock mode */

	wait_on_value(BIT0, 1, CM_IDLEST_CKGEN, LDELAY);
}

static void dpll4_init_36xx(u32 sil_index, u32 clk_index)
{
	struct dpll_per_36x_param *ptr;

	ptr = (struct dpll_per_36x_param *)get_36x_per_dpll_param();

	/* Moving it to the right sysclk base */
	ptr += clk_index;

	/* EN_PERIPH_DPLL: CM_CLKEN_PLL[16:18] */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_STOP);
	wait_on_value(BIT1, 0, CM_IDLEST_CKGEN, LDELAY);

	/* M6 (DIV_DPLL4): CM_CLKSEL1_EMU[24:29] */
	sr32(CM_CLKSEL1_EMU, 24, 6, ptr->m6);

	/* M5 (CLKSEL_CAM): CM_CLKSEL1_EMU[0:5] */
	sr32(CM_CLKSEL_CAM, 0, 6, ptr->m5);

	/* M4 (CLKSEL_DSS1): CM_CLKSEL_DSS[0:5] */
	sr32(CM_CLKSEL_DSS, 0, 6, ptr->m4);

	/* M3 (CLKSEL_DSS1): CM_CLKSEL_DSS[8:13] */
	sr32(CM_CLKSEL_DSS, 8, 6, ptr->m3);

	/* M2 (DIV_96M): CM_CLKSEL3_PLL[0:4] */
	sr32(CM_CLKSEL3_PLL, 0, 5, ptr->m2);

	/* M (PERIPH_DPLL_MULT): CM_CLKSEL2_PLL[8:19] */
	sr32(CM_CLKSEL2_PLL, 8, 12, ptr->m);

	/* N (PERIPH_DPLL_DIV): CM_CLKSEL2_PLL[0:6] */
	sr32(CM_CLKSEL2_PLL, 0, 7, ptr->n);

	/* M2DIV (CLKSEL_96M): CM_CLKSEL_CORE[12:13] */
	sr32(CM_CLKSEL_CORE, 12, 2, ptr->m2div);

	/* LOCK MODE (EN_PERIPH_DPLL): CM_CLKEN_PLL[16:18] */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_LOCK);
	wait_on_value(BIT1, 2, CM_IDLEST_CKGEN, LDELAY);
}

static void mpu_init_36xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address to MPU DPLL param table*/
	ptr = (dpll_param *)get_36x_mpu_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr = ptr + (2*clk_index) + sil_index;

	/* MPU DPLL (unlocked already) */
	/* M2 (MPU_DPLL_CLKOUT_DIV) : CM_CLKSEL2_PLL_MPU[0:4] */
	sr32(CM_CLKSEL2_PLL_MPU, 0, 5, ptr->m2);

	/* M (MPU_DPLL_MULT) : CM_CLKSEL2_PLL_MPU[8:18] */
	sr32(CM_CLKSEL1_PLL_MPU, 8, 11, ptr->m);

	/* N (MPU_DPLL_DIV) : CM_CLKSEL2_PLL_MPU[0:6] */
	sr32(CM_CLKSEL1_PLL_MPU, 0, 7, ptr->n);

	/* LOCK MODE (EN_MPU_DPLL) : CM_CLKEN_PLL_IVA2[0:2] */
	sr32(CM_CLKEN_PLL_MPU, 0, 3, PLL_LOCK);
	wait_on_value(BIT0, 1, CM_IDLEST_PLL_MPU, LDELAY);
}

static void iva_init_36xx(u32 sil_index, u32 clk_index)
{
	dpll_param *ptr;

	/* Getting the base address to IVA DPLL param table*/
	ptr = (dpll_param *)get_36x_iva_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	ptr = ptr + (2*clk_index) + sil_index;

	/* IVA DPLL */
	/* EN_IVA2_DPLL : CM_CLKEN_PLL_IVA2[0:2] */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_STOP);
	wait_on_value(BIT0, 0, CM_IDLEST_PLL_IVA2, LDELAY);

	/* M2 (IVA2_DPLL_CLKOUT_DIV) : CM_CLKSEL2_PLL_IVA2[0:4] */
	sr32(CM_CLKSEL2_PLL_IVA2, 0, 5, ptr->m2);

	/* M (IVA2_DPLL_MULT) : CM_CLKSEL1_PLL_IVA2[8:18] */
	sr32(CM_CLKSEL1_PLL_IVA2, 8, 11, ptr->m);

	/* N (IVA2_DPLL_DIV) : CM_CLKSEL1_PLL_IVA2[0:6] */
	sr32(CM_CLKSEL1_PLL_IVA2, 0, 7, ptr->n);

	/* LOCK MODE (EN_IVA2_DPLL) : CM_CLKEN_PLL_IVA2[0:2] */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_LOCK);

	wait_on_value(BIT0, 1, CM_IDLEST_PLL_IVA2, LDELAY);
}


/*
 * this prcm_init
 * is prcm_init
 * a prcm_init
 * multiline prcm_init
 * mark prcm_init
 * for  prcm_init
 * prcm_init prcm_init
 */

/******************************************************************************
 * prcm_init() - inits clocks for PRCM as defined in clocks.h
 *   -- called from SRAM, or Flash (using temp SRAM stack).
 *****************************************************************************/
void prcm_init(void)
{
	u32 osc_clk=0, sys_clkin_sel;
	u32 clk_index, sil_index;

	/* Gauge the input clock speed and find out the sys_clkin_sel
	 * value corresponding to the input clock.
	 */
	osc_clk = get_osc_clk_speed();
	get_sys_clkin_sel(osc_clk, &sys_clkin_sel);

	sr32(PRM_CLKSEL, 0, 3, sys_clkin_sel); /* set input crystal speed */

	/* If the input clock is greater than 19.2M always divide/2 */
	/*
	 * On OMAP3630, DDR data corruption has been observed on OFF mode
	 * exit if the sys clock was lower than 26M. As a work around,
	 * OMAP3630 is operated at 26M sys clock and this internal division
	 * is not performed.
	 */
	if((is_cpu_family() != CPU_OMAP36XX) && (sys_clkin_sel > 2)) {
		sr32(PRM_CLKSRC_CTRL, 6, 2, 2);/* input clock divider */
		clk_index = sys_clkin_sel/2;
	} else {
		sr32(PRM_CLKSRC_CTRL, 6, 2, 1);/* input clock divider */
		clk_index = sys_clkin_sel;
	}

	if (is_cpu_family() == CPU_OMAP36XX) {
		/*
		 * On Warm (Watchdog,RST_GS,emulator) reset after the ROM gets
		 * executed the DPLL4_CLKINP_DIV is set. It SHOULD be clear,
		 * otherwise all of the peripherals will be running 6.5 times
		 * slower than they should making it appear as though the reset
		 * did not take place
		 */
		sr32(PRM_CLKSRC_CTRL, 8, 1, 0);

		dpll3_init_36xx(0, clk_index);
		dpll4_init_36xx(0, clk_index);
		mpu_init_36xx(0, clk_index);
		iva_init_36xx(0, clk_index);
	} else {
		sil_index = get_cpu_rev() - 1;

		/* The DPLL tables are defined according to sysclk value and
		 * silicon revision. The clk_index value will be used to get
		 * the values for that input sysclk from the DPLL param table
		 * and sil_index will get the values for that SysClk for the
		 * appropriate silicon rev.
		 */

		/* Unlock MPU DPLL (slows things down, and needed later) */
		sr32(CM_CLKEN_PLL_MPU, 0, 3, PLL_LOW_POWER_BYPASS);
		wait_on_value(BIT0, 0, CM_IDLEST_PLL_MPU, LDELAY);

		dpll3_init_34xx(sil_index, clk_index);
		dpll4_init_34xx(sil_index, clk_index);
		iva_init_34xx(sil_index, clk_index);
		mpu_init_34xx(sil_index, clk_index);

		/* Lock MPU DPLL to set frequency */
		sr32(CM_CLKEN_PLL_MPU, 0, 3, PLL_LOCK);
		wait_on_value(BIT0, 1, CM_IDLEST_PLL_MPU, LDELAY);
	}

	/* Set up GPTimers to sys_clk source only */
 	sr32(CM_CLKSEL_PER, 0, 8, 0xff);
	sr32(CM_CLKSEL_WKUP, 0, 1, 1);

	delay(5000);
}

/*
 * this prcm_init eo eo eo
 * is prcm_init eo eo eo
 * a prcm_init eo eo eo
 * multiline prcm_init eo eo eo
 * mark prcm_init eo eo eo
 * for  prcm_init eo eo eo
 * prcm_init prcm_init eo eo eo
 */

/*****************************************
 * Routine: secure_unlock
 * Description: Setup security registers for access
 * (GP Device only)
 *****************************************/
void secure_unlock(void)
{
	/* Permission values for registers -Full fledged permissions to all */
	#define UNLOCK_1 0xFFFFFFFF
	#define UNLOCK_2 0x00000000
	#define UNLOCK_3 0x0000FFFF
	/* Protection Module Register Target APE (PM_RT)*/
	__raw_writel(UNLOCK_1, RT_REQ_INFO_PERMISSION_1);
	__raw_writel(UNLOCK_1, RT_READ_PERMISSION_0);
	__raw_writel(UNLOCK_1, RT_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, RT_ADDR_MATCH_1);

	__raw_writel(UNLOCK_3, GPMC_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_3, OCM_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, OCM_ADDR_MATCH_2);

	/* IVA Changes */
	__raw_writel(UNLOCK_3, IVA2_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_1, SMS_RG_ATT0); /* SDRC region 0 public */
}

/**********************************************************
 * Routine: try_unlock_sram()
 * Description: If chip is GP type, unlock the SRAM for
 *  general use.
 ***********************************************************/
void try_unlock_memory(void)
{
	int mode;

	/* if GP device unlock device SRAM for general use */
	/* secure code breaks for Secure/Emulation device - HS/E/T*/
	mode = get_device_type();
	if (mode == GP_DEVICE) {
		secure_unlock();
	}
	return;
}

/**********************************************************
 * Routine: s_init
 * Description: Does early system init of muxing and clocks.
 * - Called at time when only stack is available.
 **********************************************************/

void set_premux_env();
void s_init(void)
{
	watchdog_init();
#ifdef CONFIG_3430_AS_3410
	/* setup the scalability control register for
	 * 3430 to work in 3410 mode
	 */
	__raw_writel(0x5ABF,CONTROL_SCALABLE_OMAP_OCP);
#endif
	try_unlock_memory();
    set_premux_env();
	set_muxconf_regs();
	delay(100);
	prcm_init();
	per_clocks_enable();
}

/*******************************************************
 * Routine: misc_init_r
 * Description: Init ethernet (done here so udelay works)
 ********************************************************/
int misc_init_r (void)
{
	return(0);
}

/******************************************************
 * Routine: wait_for_command_complete
 * Description: Wait for posting to finish on watchdog
 ******************************************************/
void wait_for_command_complete(unsigned int wd_base)
{
	int pending = 1;
	do {
		pending = __raw_readl(wd_base + WWPS);
	} while (pending);
}

/****************************************
 * Routine: watchdog_init
 * Description: Shut down watch dogs
 *****************************************/
void watchdog_init(void)
{
	/* There are 3 watch dogs WD1=Secure, WD2=MPU, WD3=IVA. WD1 is
	 * either taken care of by ROM (HS/EMU) or not accessible (GP).
	 * We need to take care of WD2-MPU or take a PRCM reset.  WD3
	 * should not be running and does not generate a PRCM reset.
	 */
	sr32(CM_FCLKEN_WKUP, 5, 1, 1);
	sr32(CM_ICLKEN_WKUP, 5, 1, 1);
	wait_on_value(BIT5, 0x20, CM_IDLEST_WKUP, 5); /* some issue here */

	__raw_writel(WD_UNLOCK1, WD2_BASE + WSPR);
	wait_for_command_complete(WD2_BASE);
	__raw_writel(WD_UNLOCK2, WD2_BASE + WSPR);
}

/**********************************************
 * Routine: dram_init
 * Description: sets uboots idea of sdram size
 **********************************************/
int dram_init (void)
{
	return 0;
}

/*****************************************************************
 * Routine: peripheral_enable
 * Description: Enable the clks & power for perifs (GPT2, UART1,...)
 ******************************************************************/
void per_clocks_enable(void)
{
	/* Enable GP2 timer. */
	sr32(CM_CLKSEL_PER, 0, 1, 0x1); /* GPT2 = sys clk */
	sr32(CM_ICLKEN_PER, 3, 1, 0x1); /* ICKen GPT2 */
	sr32(CM_FCLKEN_PER, 3, 1, 0x1); /* FCKen GPT2 */

#ifdef CFG_NS16550
	/* UART 3 Clocks */
	sr32(CM_ICLKEN_PER, 11, 1, 0x1);
	sr32(CM_FCLKEN_PER, 11, 1, 0x1);

#endif

#ifdef CONFIG_DRIVER_OMAP34XX_I2C
	/* Turn on all 3 I2C clocks */ /* Came from beagle */
	sr32(CM_FCLKEN1_CORE, 15, 3, 0x7);
	sr32(CM_ICLKEN1_CORE, 15, 3, 0x7);	/* I2C1,2,3 = on */
#endif

#ifdef CONFIG_MMC
	sr32(CM_ICLKEN1_CORE, 24, 1, 0x1);
	sr32(CM_FCLKEN1_CORE, 24, 1, 0x1);
	sr32(CM_FCLKEN3_CORE,  1, 1, 0x1);
#endif
	delay(1000);
}

/* Set MUX for UART, GPMC, SDRC, GPIO */

#define 	MUX_VAL(OFFSET,VALUE)\
		__raw_writew((VALUE), OMAP34XX_CTRL_BASE + (OFFSET));

#define		CP(x)	(CONTROL_PADCONF_##x)

/*
 * M0 - Mux mode 0
 * M1 - Mux mode 1
 * M2 - Mux mode 2
 * M3 - Mux mode 3
 * M4 - Mux mode 4
 * M5 - Mux mode 5
 * M6 - Mux mode 6
 * M7 - Mux mode 7
 * IDIS - Input disabled
 * IEN - Input enabled
 * PD - Active-mode pull-down enabled
 * PU - Active-mode pull-up enabled
 * PI - Active-mode pull inhibited
 * SB_LOW - Standby mode configuration: Output low-level
 * SB_HI - Standby mode configuration: Output high-level
 * SB_HIZ - Standby mode configuration: Output hi-impedence
 * SB_PD - Standby mode pull-down enabled
 * SB_PU - Standby mode pull-up enabled
 * WKEN - Wakeup input enabled
 */

#define MUX_DEFAULT() \
MUX_VAL(CONTROL_PADCONF_GPIO_112, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_113, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_114, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_115, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_126, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_127, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_128, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPIO_129, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D0, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D1, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D2, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D3, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D4, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D5, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D6, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D7, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D8, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D9, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D10, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D11, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_FLD, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_HS, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_PCLK, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_STROBE, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_VS, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_WEN, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_XCLKA, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_XCLKB, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_DSS_ACBIAS, (IDIS | PD | M0 )) /* dss_acbias */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA0, (IDIS | PI | M1 )) /* dsi_x0 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA1, (IDIS | PI | M1 )) /* dsi_y0 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA2, (IDIS | PI | M1 )) /* dsi_x1 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA3, (IDIS | PI | M1 )) /* dsi_y1 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA4, (IDIS | PI | M1 )) /* dsi_x2 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA5, (IDIS | PI | M1 )) /* dsi_y2 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA6, (IDIS | PD | M0 )) /* dss_data6 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA7, (IDIS | PD | M0 )) /* dss_data7 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA8, (IDIS | PD | M0 )) /* dss_data8 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA9, (IDIS | PD | M0 )) /* dss_data9 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA10, (IDIS | PD | M0 )) /* dss_data10 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA11, (IDIS | PD | M0 )) /* dss_data11 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA12, (IDIS | PD | M0 )) /* dss_data12 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA13, (IDIS | PD | M0 )) /* dss_data13 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA14, (IDIS | PD | M0 )) /* dss_data14 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA15, (IDIS | PD | M0 )) /* dss_data15 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA16, (IDIS | PD | M0 )) /* dss_data16 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA17, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA18, (IDIS | PD | M0 )) /* dss_data18 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA19, (IDIS | PD | M0 )) /* dss_data19 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA20, (IDIS | PD | M0 )) /* dss_data20 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA21, (IDIS | PD | M0 )) /* dss_data21 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA22, (IDIS | PD | M0 )) /* dss_data22 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA23, (IDIS | PD | M0 )) /* dss_data23 */\
MUX_VAL(CONTROL_PADCONF_DSS_HSYNC, (IDIS | PD | M0 )) /* dss_hsync */\
MUX_VAL(CONTROL_PADCONF_DSS_PCLK, (IDIS | PD | M0 )) /* dss_pclk */\
MUX_VAL(CONTROL_PADCONF_DSS_VSYNC, (IDIS | PD | M0 )) /* dss_vsync */\
MUX_VAL(CONTROL_PADCONF_ETK_CLK_ES2, (IEN | PD | M1 )) /* mcbsp5_clkx */\
MUX_VAL(CONTROL_PADCONF_ETK_CTL_ES2, (IEN | PU | SB_PU | WKEN | M4 )) /* gpio_13 */\
MUX_VAL(CONTROL_PADCONF_ETK_D0_ES2, (IEN | PI | M4 )) /* gpio_14 */\
MUX_VAL(CONTROL_PADCONF_ETK_D1_ES2, (IEN | PU | SB_PU | WKEN | M4 )) /* gpio_15 */\
MUX_VAL(CONTROL_PADCONF_ETK_D2_ES2, (IEN | PI | M4 )) /* gpio_16 */\
MUX_VAL(CONTROL_PADCONF_ETK_D3_ES2, (IEN | PI | M4 )) /* gpio_17 */\
MUX_VAL(CONTROL_PADCONF_ETK_D4_ES2, (IEN | PD | M1 )) /* mcbsp5_dr */\
MUX_VAL(CONTROL_PADCONF_ETK_D5_ES2, (IDIS | PD | M1 )) /* mcbsp5_fsx */\
MUX_VAL(CONTROL_PADCONF_ETK_D6_ES2, (IDIS | PD | M1 )) /* mcbsp5_dx */\
MUX_VAL(CONTROL_PADCONF_ETK_D7_ES2, (IEN | PD | SB_HIZ | SB_PD | M4 )) /* gpio_21 */\
MUX_VAL(CONTROL_PADCONF_ETK_D8_ES2, (IEN | PD | SB_HIZ | SB_PD | M4 )) /* gpio_22 */\
MUX_VAL(CONTROL_PADCONF_ETK_D9_ES2, (IDIS | PD | M4 )) /* gpio_23 */\
MUX_VAL(CONTROL_PADCONF_ETK_D10_ES2, (IDIS | PD | M4 )) /* gpio_24 */\
MUX_VAL(CONTROL_PADCONF_ETK_D11_ES2, (IDIS | PD | M4 )) /* gpio_25 */\
MUX_VAL(CONTROL_PADCONF_ETK_D12_ES2, (IDIS | PD | M4 )) /* gpio_26 */\
MUX_VAL(CONTROL_PADCONF_ETK_D13_ES2, (IDIS | PD | M4 )) /* gpio_27 */\
MUX_VAL(CONTROL_PADCONF_ETK_D14_ES2, (IDIS | PD | M4 )) /* gpio_28 */\
MUX_VAL(CONTROL_PADCONF_ETK_D15_ES2, (IDIS | PD | M4 )) /* gpio_29 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A1, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A2, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A3, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A4, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A5, (IDIS | PD | M4 )) /* gpio_38 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A6, (IDIS | PU | M4 )) /* gpio_39 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A7, (IEN | PU | SB_PU | WKEN | M4 )) /* gpio_40 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A8, (IEN | PI | M4 )) /* gpio_41 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A9, (IEN | PU | M4 )) /* gpio_42 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A10, (IDIS | PU | M4 )) /* gpio_43 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A11, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_CLK, (IEN | PI | M0 )) /* gpmc_clk */\
MUX_VAL(CONTROL_PADCONF_GPMC_D0, (IEN | PU | M0 )) /* gpmc_d0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D1, (IEN | PU | M0 )) /* gpmc_d1 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D2, (IEN | PU | M0 )) /* gpmc_d2 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D3, (IEN | PU | M0 )) /* gpmc_d3 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D4, (IEN | PU | M0 )) /* gpmc_d4 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D5, (IEN | PU | M0 )) /* gpmc_d5 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D6, (IEN | PU | M0 )) /* gpmc_d6 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D7, (IEN | PU | M0 )) /* gpmc_d7 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D8, (IEN | PU | M0 )) /* gpmc_d8 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D9, (IEN | PU | M0 )) /* gpmc_d9 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D10, (IEN | PU | M0 )) /* gpmc_d10 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D11, (IEN | PU | M0 )) /* gpmc_d11 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D12, (IEN | PU | M0 )) /* gpmc_d12 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D13, (IEN | PU | M0 )) /* gpmc_d13 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D14, (IEN | PU | M0 )) /* gpmc_d14 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D15, (IEN | PU | M0 )) /* gpmc_d15 */\
MUX_VAL(CONTROL_PADCONF_GPMC_NADV_ALE, (IDIS | PI | M0 )) /* gpmc_nadv_ale */\
MUX_VAL(CONTROL_PADCONF_GPMC_NBE0_CLE, (IDIS | PI | M0 )) /* gpmc_nbe0_cle */\
MUX_VAL(CONTROL_PADCONF_GPMC_NBE1, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS0, (IDIS | PI | M0 )) /* gpmc_ncs0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS1, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS2, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS3, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS4, (IEN | PD | M2 )) /* mcbsp4_clkx */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS5, (IEN | PD | M2 )) /* mcbsp4_dr */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS6, (IDIS | PD | M2 )) /* mcbsp4_dx */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS7, (IDIS | PD | M2 )) /* mcbsp4_fsx */\
MUX_VAL(CONTROL_PADCONF_GPMC_NOE, (IDIS | PI | M0 )) /* gpmc_noe */\
MUX_VAL(CONTROL_PADCONF_GPMC_NWE, (IDIS | PI | M0 )) /* gpmc_nwe */\
MUX_VAL(CONTROL_PADCONF_GPMC_NWP, (IDIS | PI | M0 )) /* gpmc_nwp */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT0, (IEN | PI | M0 )) /* gpmc_wait0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT1, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT2, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT3, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_HDQ_SIO, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_CLK, (IEN | PI | M0 )) /* hsusb0_clk */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA0, (IEN | PI | M0 )) /* hsusb0_data0 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA1, (IEN | PI | M0 )) /* hsusb0_data1 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA2, (IEN | PI | M0 )) /* hsusb0_data2 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA3, (IEN | PI | M0 )) /* hsusb0_data3 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA4, (IEN | PI | M0 )) /* hsusb0_data4 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA5, (IEN | PI | M0 )) /* hsusb0_data5 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA6, (IEN | PI | M0 )) /* hsusb0_data6 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA7, (IEN | PI | M0 )) /* hsusb0_data7 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DIR, (IEN | PI | M0 )) /* hsusb0_dir */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_NXT, (IEN | PI | M0 )) /* hsusb0_nxt */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_STP, (IDIS | PI | M0 )) /* hsusb0_stp */\
MUX_VAL(CONTROL_PADCONF_I2C1_SCL, (IEN | PI | M0 )) /* i2c1_scl */\
MUX_VAL(CONTROL_PADCONF_I2C1_SDA, (IEN | PI | M0 )) /* i2c1_sda */\
MUX_VAL(CONTROL_PADCONF_I2C2_SCL, (IEN | PI | M0 )) /* i2c2_scl */\
MUX_VAL(CONTROL_PADCONF_I2C2_SDA, (IEN | PI | M0 )) /* i2c2_sda */\
MUX_VAL(CONTROL_PADCONF_I2C3_SCL, (IEN | PI | M0 )) /* i2c3_scl */\
MUX_VAL(CONTROL_PADCONF_I2C3_SDA, (IEN | PI | M0 )) /* i2c3_sda */\
MUX_VAL(CONTROL_PADCONF_I2C4_SCL, (IEN | PI | M0 )) /* i2c4_scl */\
MUX_VAL(CONTROL_PADCONF_I2C4_SDA, (IEN | PI | M0 )) /* i2c4_sda */\
MUX_VAL(CONTROL_PADCONF_JTAG_EMU0, (IEN | PI | M0 )) /* jtag_emu0 */\
MUX_VAL(CONTROL_PADCONF_JTAG_EMU1, (IEN | PI | M0 )) /* jtag_emu1 */\
MUX_VAL(CONTROL_PADCONF_JTAG_NTRST, (IEN | PI | M0 )) /* jtag_ntrst */\
MUX_VAL(CONTROL_PADCONF_JTAG_RTCK, (IDIS | PI | M0 )) /* jtag_rtck */\
MUX_VAL(CONTROL_PADCONF_JTAG_TCK, (IEN | PD | M0 )) /* jtag_tck */\
MUX_VAL(CONTROL_PADCONF_JTAG_TDI, (IEN | PU | M0 )) /* jtag_tdi */\
MUX_VAL(CONTROL_PADCONF_JTAG_TDO, (IDIS | PI | M0 )) /* jtag_tdo */\
MUX_VAL(CONTROL_PADCONF_JTAG_TMS, (IEN | PU | M0 )) /* jtag_tms_tmsc */\
MUX_VAL(CONTROL_PADCONF_MCBSP_CLKS, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_CLKR, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_CLKX, (IEN | PD | M2 )) /* mcbsp3_clkx */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_DR, (IEN | PD | M2 )) /* mcbsp3_dr */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_DX, (IDIS | PD | M2 )) /* mcbsp3_dx */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_FSR, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_FSX, (IEN | PD | M2 )) /* mcbsp3_fsx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_CLKX, (IEN | PD | M0 )) /* mcbsp2_clkx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_DR, (IEN | PD | M0 )) /* mcbsp2_dr */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_DX, (IDIS | PD | M0 )) /* mcbsp2_dx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_FSX, (IEN | PD | M0 )) /* mcbsp2_fsx */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_CLKX, (IDIS | PU | M1 )) /* uart2_tx */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_DR, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_DX, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_FSX, (IEN | PU | M1 )) /* uart2_rx */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_CLKX, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_DR, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_DX, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_FSX, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CLK, (IEN | PD | M0 )) /* mcspi1_clk */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS0, (IDIS | PU | M0 )) /* mcspi1_cs0 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS1, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS2, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS3, (IDIS | PU | M0 )) /* mcspi1_cs3 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_SIMO, (IDIS | PD | M0 )) /* mcspi1_simo */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_SOMI, (IEN | PD | M0 )) /* mcspi1_somi */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CLK, (IDIS | PD | M4 )) /* gpio_178 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CS0, (IDIS | PU | M4 )) /* gpio_181 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CS1, (IDIS | PD | M1 )) /* gpt_8_pwm_evt */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_SIMO, (IDIS | PD | M1 )) /* gpt_9_pwm_evt */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_SOMI, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC1_CLK, (IEN | PU | M0 )) /* mmc1_clk */\
MUX_VAL(CONTROL_PADCONF_MMC1_CMD, (IDIS | PU | M0 )) /* mmc1_cmd */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT0, (IEN | PU | M0 )) /* mmc1_dat0 */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT1, (IEN | PU | M0 )) /* mmc1_dat1 */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT2, (IEN | PU | M0 )) /* mmc1_dat2 */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT3, (IEN | PU | M0 )) /* mmc1_dat3 */\
MUX_VAL(CONTROL_PADCONF_MMC2_CLK, (IEN | PU | M0 )) /* mmc2_clk */\
MUX_VAL(CONTROL_PADCONF_MMC2_CMD, (IDIS | PU | M0 )) /* mmc2_cmd */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT0, (IEN | PU | M0 )) /* mmc2_dat0 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT1, (IEN | PU | M0 )) /* mmc2_dat1 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT2, (IEN | PU | M0 )) /* mmc2_dat2 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT3, (IEN | PU | M0 )) /* mmc2_dat3 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT4, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT5, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT6, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT7, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_SDRC_A0, (IDIS | PI | M0 )) /* sdrc_a0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A1, (IDIS | PI | M0 )) /* sdrc_a1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A2, (IDIS | PI | M0 )) /* sdrc_a2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A3, (IDIS | PI | M0 )) /* sdrc_a3 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A4, (IDIS | PI | M0 )) /* sdrc_a4 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A5, (IDIS | PI | M0 )) /* sdrc_a5 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A6, (IDIS | PI | M0 )) /* sdrc_a6 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A7, (IDIS | PI | M0 )) /* sdrc_a7 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A8, (IDIS | PI | M0 )) /* sdrc_a8 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A9, (IDIS | PI | M0 )) /* sdrc_a9 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A10, (IDIS | PI | M0 )) /* sdrc_a10 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A11, (IDIS | PI | M0 )) /* sdrc_a11 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A12, (IDIS | PI | M0 )) /* sdrc_a12 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A13, (IDIS | PI | M0 )) /* sdrc_a13 */\
MUX_VAL(CONTROL_PADCONF_SDRC_A14, (IDIS | PI | M0 )) /* sdrc_a14 */\
MUX_VAL(CONTROL_PADCONF_SDRC_BA0, (IDIS | PI | M0 )) /* sdrc_ba0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_BA1, (IDIS | PI | M0 )) /* sdrc_ba1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_CKE0, (IDIS | PI | M0 )) /* sdrc_cke0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_CKE1, (IDIS | PI | M0 )) /* sdrc_cke1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_CLK, (IEN | PI | M0 )) /* sdrc_clk */\
MUX_VAL(CONTROL_PADCONF_SDRC_D0, (IEN | PI | M0 )) /* sdrc_d0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D1, (IEN | PI | M0 )) /* sdrc_d1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D2, (IEN | PI | M0 )) /* sdrc_d2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D3, (IEN | PI | M0 )) /* sdrc_d3 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D4, (IEN | PI | M0 )) /* sdrc_d4 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D5, (IEN | PI | M0 )) /* sdrc_d5 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D6, (IEN | PI | M0 )) /* sdrc_d6 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D7, (IEN | PI | M0 )) /* sdrc_d7 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D8, (IEN | PI | M0 )) /* sdrc_d8 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D9, (IEN | PI | M0 )) /* sdrc_d9 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D10, (IEN | PI | M0 )) /* sdrc_d10 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D11, (IEN | PI | M0 )) /* sdrc_d11 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D12, (IEN | PI | M0 )) /* sdrc_d12 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D13, (IEN | PI | M0 )) /* sdrc_d13 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D14, (IEN | PI | M0 )) /* sdrc_d14 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D15, (IEN | PI | M0 )) /* sdrc_d15 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D16, (IEN | PI | M0 )) /* sdrc_d16 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D17, (IEN | PI | M0 )) /* sdrc_d17 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D18, (IEN | PI | M0 )) /* sdrc_d18 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D19, (IEN | PI | M0 )) /* sdrc_d19 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D20, (IEN | PI | M0 )) /* sdrc_d20 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D21, (IEN | PI | M0 )) /* sdrc_d21 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D22, (IEN | PI | M0 )) /* sdrc_d22 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D23, (IEN | PI | M0 )) /* sdrc_d23 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D24, (IEN | PI | M0 )) /* sdrc_d24 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D25, (IEN | PI | M0 )) /* sdrc_d25 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D26, (IEN | PI | M0 )) /* sdrc_d26 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D27, (IEN | PI | M0 )) /* sdrc_d27 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D28, (IEN | PI | M0 )) /* sdrc_d28 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D29, (IEN | PI | M0 )) /* sdrc_d29 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D30, (IEN | PI | M0 )) /* sdrc_d30 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D31, (IEN | PI | M0 )) /* sdrc_d31 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DM0, (IDIS | PI | M0 )) /* sdrc_dm0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DM1, (IDIS | PI | M0 )) /* sdrc_dm1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DM2, (IDIS | PI | M0 )) /* sdrc_dm2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DM3, (IDIS | PI | M0 )) /* sdrc_dm3 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS0, (IEN | PI | M0 )) /* sdrc_dqs0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS1, (IEN | PI | M0 )) /* sdrc_dqs1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS2, (IEN | PI | M0 )) /* sdrc_dqs2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS3, (IEN | PI | M0 )) /* sdrc_dqs3 */\
MUX_VAL(CONTROL_PADCONF_SDRC_NCAS, (IDIS | PI | M0 )) /* sdrc_ncas */\
MUX_VAL(CONTROL_PADCONF_SDRC_NCLK, (IEN | PI | M0 )) /* sdrc_nclk */\
MUX_VAL(CONTROL_PADCONF_SDRC_NCS0, (IDIS | PI | M0 )) /* sdrc_ncs0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_NCS1, (IDIS | PI | M0 )) /* sdrc_ncs1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_NRAS, (IDIS | PI | M0 )) /* sdrc_nras */\
MUX_VAL(CONTROL_PADCONF_SDRC_NWE, (IDIS | PI | M0 )) /* sdrc_nwe */\
MUX_VAL(CONTROL_PADCONF_SYS_32K, (IEN | PI | M0 )) /* sys_32k */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT0, (IEN | PI | M0 )) /* sys_boot0 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT1, (IEN | PI | M0 )) /* sys_boot1 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT2, (IEN | PI | M0 )) /* sys_boot2 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT3, (IEN | PI | M0 )) /* sys_boot3 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT4, (IEN | PI | M0 )) /* sys_boot4 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT5, (IEN | PI | M0 )) /* sys_boot5 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT6, (IEN | PI | M0 )) /* sys_boot6 */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKOUT1, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKOUT2, (IEN | PD | SB_HIZ | SB_PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKREQ, (IEN | PI | M0 )) /* sys_clkreq */\
MUX_VAL(CONTROL_PADCONF_SYS_NIRQ, (IEN | PU | SB_PU | WKEN | M0 )) /* sys_nirq */\
MUX_VAL(CONTROL_PADCONF_SYS_NRESWARM, (IEN | PI | M0 )) /* sys_nreswarm */\
MUX_VAL(CONTROL_PADCONF_SYS_OFF_MODE, (IDIS | PD | M0 )) /* sys_off_mode */\
MUX_VAL(CONTROL_PADCONF_UART1_CTS, (IEN | PI | M0 )) /* uart1_cts */\
MUX_VAL(CONTROL_PADCONF_UART1_RTS, (IDIS | PU | M0 )) /* uart1_rts */\
MUX_VAL(CONTROL_PADCONF_UART1_RX, (IEN | PI | M0 )) /* uart1_rx */\
MUX_VAL(CONTROL_PADCONF_UART1_TX, (IDIS | PU | M0 )) /* uart1_tx */\
MUX_VAL(CONTROL_PADCONF_UART2_CTS, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_UART2_RTS, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_UART2_RX, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_UART2_TX, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_UART3_CTS_RCTX, (IEN | PU | M0 )) /* uart3_cts_rctx */\
MUX_VAL(CONTROL_PADCONF_UART3_RTS_SD, (IDIS | PU | M0 )) /* uart3_rts_sd */\
MUX_VAL(CONTROL_PADCONF_UART3_RX_IRRX, (IEN | PU | M0 )) /* uart3_rx_irrx */\
MUX_VAL(CONTROL_PADCONF_UART3_TX_IRTX, (IDIS | PU | M0 )) /* uart3_tx_irtx */\


/**********************************************************
 * Routine: set_premux_env
 * Description: Have to setup gpio prio to muxing in order
 *              for periphs to start up in a defined state
 *              once MUXing is done. Plus set PWM for
 *              LCD and kbd brightness control...
 *********************************************************/
#define GPT_TCLR_DFLT_VALUE  0x00001842
#define GPT_TLDR_DFLT_VALUE  0xffffffdf
#define GPT_TMAR_DFLT_VALUE  0x000000ff
void set_premux_env()
{
    uint32_t mask0;
    uint32_t mask1;
    uint32_t mask5;
    uint32_t val;

#ifdef PWM_SETUP
    /* ************** Do PWM setup  ******************* */

    /*
     * Note to self from the days of 3530:
     * It appears that there's a mess accessing GPT11 registers
     * when GPT's FCLK is sourced from sys_32k. It's likely to work
     * this way: First source FCLK from sys_clk, configure
     * GPT's register, set FCLK's source to sys_32k. Otherwise device
     * hangs on accessing GPT's register when FLCK is sourced
     * from sys_32k.
     */

    /* TODO: Ask Roma about the way this PWM works. */

    /* FIXME: Should this ever work/be prio to prcm_init */

    /* Provide GPTs with clocks */
    sr32(CM_CLKSEL_PER, 6, 2, 0x3);  /* GPT8,9 -- Use sys_clk */
    sr32(CM_ICLKEN_PER, 9, 2, 0x3);  /* GPT8,9 -- Get I-clk */
    sr32(CM_FCLKEN_PER, 9, 2, 0x3);  /* GPT8,9 -- Get F-clk */

	/* Setting PWM on GP8,9 timer. */
	/* Set TCLR and stop the timer now */
	__raw_writel(GPT_TCLR_DFLT_VALUE, GPT8_TCLR);
	__raw_writel(GPT_TLDR_DFLT_VALUE, GPT8_TLDR);
	__raw_writel(GPT_TMAR_DFLT_VALUE, GPT8_TMAR);
	__raw_writel(0xffffffff - 3,      GPT8_TCRR);

	__raw_writel(GPT_TCLR_DFLT_VALUE, GPT9_TCLR);
	__raw_writel(GPT_TLDR_DFLT_VALUE, GPT9_TLDR);
	__raw_writel(GPT_TMAR_DFLT_VALUE, GPT9_TMAR);
	__raw_writel(0xffffffff - 3,      GPT9_TCRR);

	/* Start timer. Bit[0] = 1. And source fclk. */
	sr32(GPT8_TCLR, 0, 1, 1);
	sr32(GPT9_TCLR, 0, 1, 1);
	sr32(CM_CLKSEL_PER, 6, 2, 0x0 ); /* 32Khz source, though hw default */
#endif

    /* Provide ICLK & FCLK to all GPIO modules */
    val = __raw_readl(CM_ICLKEN_WKUP) | BIT3;
    __raw_writel(val, CM_ICLKEN_WKUP);
    val = __raw_readl(CM_FCLKEN_WKUP) | BIT3;
    __raw_writel(val, CM_FCLKEN_WKUP);
    val = __raw_readl(CM_ICLKEN_PER) | BIT13 | BIT14 | BIT15 | BIT16 | BIT17;
    __raw_writel(val, CM_ICLKEN_PER);
    val = __raw_readl(CM_FCLKEN_PER) | BIT13 | BIT14 | BIT15 | BIT16 | BIT17;
    __raw_writel(val, CM_FCLKEN_PER);
    delay(1000);

    /* ************** Do GPIO setup ******************* */
    mask0 = 0;
    mask0 |= GPIO_MASK_IN_BANK(24) | GPIO_MASK_IN_BANK(26) |
        GPIO_MASK_IN_BANK(25) | GPIO_MASK_IN_BANK(27) |
        GPIO_MASK_IN_BANK(28) | GPIO_MASK_IN_BANK(29) |
        GPIO_MASK_IN_BANK(23);

    mask1 = 0;
    mask1 |= GPIO_MASK_IN_BANK(38) | GPIO_MASK_IN_BANK(39) |
        GPIO_MASK_IN_BANK(43);

    mask5 = 0;
    mask5 |= GPIO_MASK_IN_BANK(181) | GPIO_MASK_IN_BANK(178);

    /* Set GPIOi.DATAOUT registers */
    /* Everything we want in BANK0 should be zeroed */
    *((uint32_t *)GPIO_DATAOUT_ADDR(24))  &= ~mask0;

    /* BANK1 dataout may vary */
    *((uint32_t *)GPIO_DATAOUT_ADDR(43))  &= ~(GPIO_MASK_IN_BANK(43));
    *((uint32_t *)GPIO_DATAOUT_ADDR(38))  |= GPIO_MASK_IN_BANK(38) | GPIO_MASK_IN_BANK(39);

    /* BANK5 dataout may vary */
    *((uint32_t *)GPIO_DATAOUT_ADDR(181)) |= GPIO_MASK_IN_BANK(181);
    *((uint32_t *)GPIO_DATAOUT_ADDR(178)) &= ~(GPIO_MASK_IN_BANK(178));

    /* Set GPIOi.OE registers */
    *((uint32_t *)GPIO_OE_ADDR(24))  &= ~mask0;
    *((uint32_t *)GPIO_OE_ADDR(38))  &= ~mask1;
    *((uint32_t *)GPIO_OE_ADDR(181)) &= ~mask5;

}

/**********************************************************
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers
 *              specific to the hardware. Many pins need
 *              to be moved from protect to primary mode.
 *********************************************************/
void set_muxconf_regs(void)
{
	MUX_DEFAULT();
}

int nor_read_boot(unsigned char *buf)
{
	return 0;
}

/**********************************************************
 * Routine: nand+_init
 * Description: Set up nand for nand and jffs2 commands
 *********************************************************/

#define GPMC_CONF1_ORION 0x00001800
#define GPMC_CONF2_ORION 0x00050900
#define GPMC_CONF3_ORION 0x00050502
#define GPMC_CONF4_ORION 0x04020301
#define GPMC_CONF5_ORION 0x04030403

/* Use 0 or 1. */
#define USE_GPMC_ORION 0
int nand_init(void)
{
	/* global settings */
	__raw_writel(0x10, GPMC_SYSCONFIG);	/* smart idle */
	__raw_writel(0x0, GPMC_IRQENABLE);	/* isr's sources masked */
	__raw_writel(0, GPMC_TIMEOUT_CONTROL);/* timeout disable */

	/* Set the GPMC Vals . For NAND boot on 3430SDP, NAND is mapped at CS0
         *  , NOR at CS1 and MPDB at CS3. And oneNAND boot, we map oneNAND at CS0.
	 *  We configure only GPMC CS0 with required values. Configiring other devices
	 *  at other CS in done in u-boot anyway. So we don't have to bother doing it here.
         */
	__raw_writel(0 , GPMC_CONFIG7 + GPMC_CONFIG_CS0);
	delay(1000);
#ifdef ECC_HW_ENABLE
	if (get_mem_type() == GPMC_NAND){
        __raw_writel( (ECCCLEAR | ECCRESULTREG1), GPMC_ECC_CONTROL + GPMC_CONFIG_CS0);
        __raw_writel( (ECCSIZE1 | ECCSIZE0 | ECCSIZE0SEL), GPMC_ECC_SIZE_CONFIG + GPMC_CONFIG_CS0);
	}
#endif
	if ((get_mem_type() == GPMC_NAND) || (get_mem_type() == MMC_NAND)){
#if USE_GPMC_ORION > 0
        __raw_writel( GPMC_CONF1_ORION /*M_NAND_GPMC_CONFIG1*/, GPMC_CONFIG1 + GPMC_CONFIG_CS0);
        __raw_writel( GPMC_CONF2_ORION, GPMC_CONFIG2 + GPMC_CONFIG_CS0);
        __raw_writel( GPMC_CONF3_ORION, GPMC_CONFIG3 + GPMC_CONFIG_CS0);
        __raw_writel( GPMC_CONF4_ORION, GPMC_CONFIG4 + GPMC_CONFIG_CS0);
        __raw_writel( GPMC_CONF5_ORION, GPMC_CONFIG5 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG6, GPMC_CONFIG6 + GPMC_CONFIG_CS0);
#else
        __raw_writel( M_NAND_GPMC_CONFIG1, GPMC_CONFIG1 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG2, GPMC_CONFIG2 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG3, GPMC_CONFIG3 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG4, GPMC_CONFIG4 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG5, GPMC_CONFIG5 + GPMC_CONFIG_CS0);
        __raw_writel( M_NAND_GPMC_CONFIG6, GPMC_CONFIG6 + GPMC_CONFIG_CS0);
#endif

        	/* Enable the GPMC Mapping */
        	__raw_writel(( ((OMAP34XX_GPMC_CS0_SIZE & 0xF)<<8) |
        		     ((NAND_BASE_ADR>>24) & 0x3F) |
        		     (1<<6) ),  (GPMC_CONFIG7 + GPMC_CONFIG_CS0));
        	delay(2000);

         	if (nand_chip()){
#ifdef CFG_PRINTF
        		printf("Unsupported Chip!\n");
#endif
        		return 1;
        	}

	}

	if ((get_mem_type() == GPMC_ONENAND) || (get_mem_type() == MMC_ONENAND)){
#ifdef CFG_PRINTF
        printf("OneNAND?! Don't have it @ all.\n");
#endif
        		return 1;
	}
	return 0;
}

#ifdef ECC_HW_ENABLE
void omap_enable_hw_ecc(void)
{
	uint32_t val,dev_width = 0;
        uint8_t cs = 0;
#ifdef NAND_16BIT
	dev_width = 1;
#endif
	/* Clear the ecc result registers, select ecc reg as 1 */
	__raw_writel(ECCCLEAR | ECCRESULTREG1, GPMC_ECC_CONTROL + GPMC_CONFIG_CS0);

	/*
	* Size 0 = 0xFF, Size1 is 0xFF - both are 512 bytes
	* tell all regs to generate size0 sized regs
	* we just have a single ECC engine for all CS
	*/
	__raw_writel(ECCSIZE1 | ECCSIZE0 | ECCSIZE0SEL,
			GPMC_ECC_SIZE_CONFIG + GPMC_CONFIG_CS0);
	val = (dev_width << 7) | (cs << 1) | (0x1);
	__raw_writel(val, GPMC_ECC_CONFIG + GPMC_CONFIG_CS0);
	return;
}
/*
 * hweightN: returns the hamming weight (i.e. the number
 * of bits set) of a N-bit word
 */

static inline unsigned int hweight32(unsigned int w)
{
        unsigned int res = (w & 0x55555555) + ((w >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res & 0x0F0F0F0F) + ((res >> 4) & 0x0F0F0F0F);
        res = (res & 0x00FF00FF) + ((res >> 8) & 0x00FF00FF);
        return (res & 0x0000FFFF) + ((res >> 16) & 0x0000FFFF);
}
/*
 * gen_true_ecc - This function will generate true ECC value, which
 * can be used when correcting data read from NAND flash memory core
 *
 * @ecc_buf:    buffer to store ecc code
 *
 * @return:     re-formatted ECC value
 */
static uint32_t gen_true_ecc(uint8_t *ecc_buf)
{
        return ecc_buf[0] | (ecc_buf[1] << 16) | ((ecc_buf[2] & 0xF0) << 20) |
                ((ecc_buf[2] & 0x0F) << 8);
}


int omap_correct_data_hw_ecc(u_char *dat, u_char *read_ecc, u_char *calc_ecc)
{
        uint32_t orig_ecc, new_ecc, res, hm;
        uint16_t parity_bits, byte;
        uint8_t bit;

        /* Regenerate the orginal ECC */
        orig_ecc = gen_true_ecc(read_ecc);
        new_ecc = gen_true_ecc(calc_ecc);
        /* Get the XOR of real ecc */
        res = orig_ecc ^ new_ecc;
        if (res) {
                /* Get the hamming width */
                hm = hweight32(res);
                /* Single bit errors can be corrected! */
                if (hm == 12) {
                        /* Correctable data! */
                        parity_bits = res >> 16;
                        bit = (parity_bits & 0x7);
                        byte = (parity_bits >> 3) & 0x1FF;
                        /* Flip the bit to correct */
                        dat[byte] ^= (0x1 << bit);
                } else if (hm == 1) {
                        printf("Error: Ecc is wrong\n");
                        /* ECC itself is corrupted */
                        return 2;
                } else {
                        /*
                         * hm distance != parity pairs OR one, could mean 2 bit
                         * error OR potentially be on a blank page..
                         * orig_ecc: contains spare area data from nand flash.
                         * new_ecc: generated ecc while reading data area.
                         * Note: if the ecc = 0, all data bits from which it was
                         * generated are 0xFF.
                         * The 3 byte(24 bits) ecc is generated per 512byte
                         * chunk of a page. If orig_ecc(from spare area)
                         * is 0xFF && new_ecc(computed now from data area)=0x0,
                         * this means that data area is 0xFF and spare area is
                         * 0xFF. A sure sign of a erased page!
                         */
                        if ((orig_ecc == 0x0FFF0FFF) && (new_ecc == 0x00000000))
                                return 0;
                        printf("Error: Bad compare! failed\n");
                        /* detected 2 bit error */
                        return -1;
                }
        }
        return 0;
}
void omap_calculate_hw_ecc(const u_char *dat, u_char *ecc_code)
{
        u_int32_t val;

        /* Start Reading from HW ECC1_Result = 0x200 */
        val = __raw_readl(GPMC_ECC1_RESULT + GPMC_CONFIG_CS0);

        ecc_code[0] = val & 0xFF;
        ecc_code[1] = (val >> 16) & 0xFF;
        ecc_code[2] = ((val >> 8) & 0x0F) | ((val >> 20) & 0xF0);

        /*
         * Stop reading anymore ECC vals and clear old results
         * enable will be called if more reads are required
         */
	__raw_writel(0x000 , GPMC_ECC_CONFIG + GPMC_CONFIG_CS0);

        return;
}
#endif
typedef int (mmc_boot_addr) (void);
int mmc_boot(unsigned char *buf)
{

       long size = 0;
#ifdef CFG_CMD_FAT
       block_dev_desc_t *dev_desc = NULL;
       unsigned char ret = 0;

       printf("Starting X-loader on MMC\n");

       ret = mmc_init(1);
       if(ret == 0){
               printf("\n MMC init failed\n");
               return 0;
       }

       dev_desc = mmc_get_dev(0);
       fat_register_device(dev_desc, 1);
       size = file_fat_read("u-boot.bin", buf, 0);
       if (size == -1) {
               return 0;
       }
       printf("\n%ld Bytes Read from MMC\n", size);

       printf("Starting OS Bootloader from MMC...\n");
#endif
       return size;
}

/* optionally do something like blinking LED */
void board_hang (void)
{ while (0) {};}

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void raise(void)
{
}

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void abort(void)
{
}
