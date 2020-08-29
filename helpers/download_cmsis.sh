#! /bin/sh

STM32G0_URL=https://raw.githubusercontent.com/STMicroelectronics/STM32CubeWB/master

mkdir CMSIS

HEADERS="\
  Include/cmsis_compiler.h \
  Include/cmsis_gcc.h \
  Include/cmsis_version.h \
  Include/core_cm4.h \
  Include/mpu_armv7.h \
  Device/ST/STM32WBxx/Include/stm32wb55xx.h \
  Device/ST/STM32WBxx/Include/stm32wbxx.h \
  Device/ST/STM32WBxx/Include/system_stm32wbxx.h \
"

for file in $HEADERS
do
  name=`basename $file`
  curl -L $STM32G0_URL/Drivers/CMSIS/$file -o CMSIS/$name
  sed -i 's/\ *$//' CMSIS/$name
done
