#!/bin/bash
#
#

#export BUILD_DIR=$PWD/build/

#make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- distclean
#make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- orion2_config
#make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi-

make clean
make orion2_config
make
