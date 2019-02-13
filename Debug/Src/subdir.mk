################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/main.c \
../Src/stm32l1xx_hal_msp.c \
../Src/stm32l1xx_it.c \
../Src/system_stm32l1xx.c 

OBJS += \
./Src/freertos.o \
./Src/main.o \
./Src/stm32l1xx_hal_msp.o \
./Src/stm32l1xx_it.o \
./Src/system_stm32l1xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/main.d \
./Src/stm32l1xx_hal_msp.d \
./Src/stm32l1xx_it.d \
./Src/system_stm32l1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L152xE -I"/home/gecko/workspace/NucleoSquashy/Inc" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/SSD1306/Inc" -I"/home/gecko/workspace/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc" -I"/home/gecko/workspace/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc/Legacy" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"/home/gecko/workspace/NucleoSquashy/Drivers/CMSIS/Device/ST/STM32L1xx/Include" -I"/home/gecko/workspace/NucleoSquashy/Drivers/CMSIS/Include" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/Squashy/gamesys"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


