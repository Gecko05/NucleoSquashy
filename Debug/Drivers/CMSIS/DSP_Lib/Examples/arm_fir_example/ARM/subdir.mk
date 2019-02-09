################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_data.c \
../Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_example_f32.c \
../Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/math_helper.c 

OBJS += \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_data.o \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_example_f32.o \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/math_helper.o 

C_DEPS += \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_data.d \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/arm_fir_example_f32.d \
./Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/math_helper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/%.o: ../Drivers/CMSIS/DSP_Lib/Examples/arm_fir_example/ARM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L152xE -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Inc" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Drivers/STM32L1xx_HAL_Driver/Inc/Legacy" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Drivers/CMSIS/Device/ST/STM32L1xx/Include" -I"/home/gecko/Embedded/STM/Projects/NucleoSquashy/NucleoSquashy/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


