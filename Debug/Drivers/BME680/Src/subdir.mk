################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BME680/Src/bme68x.c 

OBJS += \
./Drivers/BME680/Src/bme68x.o 

C_DEPS += \
./Drivers/BME680/Src/bme68x.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BME680/Src/%.o Drivers/BME680/Src/%.su Drivers/BME680/Src/%.cyclo: ../Drivers/BME680/Src/%.c Drivers/BME680/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../SubGHz_Phy/App -I../SubGHz_Phy/Target -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/timer -I../Utilities/lpm/tiny_lpm -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Middlewares/Third_Party/SubGHz_Phy -I../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../Drivers/CMSIS/Include -I"/home/base_usr/TFE_sw/Drivers/BME680/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BME680-2f-Src

clean-Drivers-2f-BME680-2f-Src:
	-$(RM) ./Drivers/BME680/Src/bme68x.cyclo ./Drivers/BME680/Src/bme68x.d ./Drivers/BME680/Src/bme68x.o ./Drivers/BME680/Src/bme68x.su

.PHONY: clean-Drivers-2f-BME680-2f-Src

