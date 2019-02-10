################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/gamesys/gameobject.c \
../Middlewares/gamesys/gamesys.c \
../Middlewares/gamesys/sprites.c 

OBJS += \
./Middlewares/gamesys/gameobject.o \
./Middlewares/gamesys/gamesys.o \
./Middlewares/gamesys/sprites.o 

C_DEPS += \
./Middlewares/gamesys/gameobject.d \
./Middlewares/gamesys/gamesys.d \
./Middlewares/gamesys/sprites.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/gamesys/%.o: ../Middlewares/gamesys/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L152xE -I"/home/gecko/workspace/NucleoSquashy/Inc" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/SSD1306/Inc" -I"/home/gecko/workspace/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc" -I"/home/gecko/workspace/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc/Legacy" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"/home/gecko/workspace/NucleoSquashy/Drivers/CMSIS/Device/ST/STM32L1xx/Include" -I"/home/gecko/workspace/NucleoSquashy/Drivers/CMSIS/Include" -I"/home/gecko/workspace/NucleoSquashy/Middlewares/gamesys"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


