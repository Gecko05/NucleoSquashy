################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xb.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xba.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xc.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xb.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xba.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xc.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xca.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xd.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xdx.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xe.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xb.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xba.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xc.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xca.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xd.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xdx.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xe.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xc.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xca.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xd.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xdx.s \
../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xe.s 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xb.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xba.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l100xc.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xb.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xba.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xc.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xca.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xd.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xdx.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l151xe.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xb.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xba.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xc.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xca.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xd.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xdx.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l152xe.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xc.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xca.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xd.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xdx.o \
./Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/startup_stm32l162xe.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/%.o: ../Drivers/CMSIS/Device/ST/STM32L1xx/Source/Templates/iar/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


