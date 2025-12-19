################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.c 

C_DEPS += \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.d 

OBJS += \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.o Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.su Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.cyclo: ../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/%.c Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Core/Repo/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Core/Repo/USB_DEVICE/App -I../Core/Repo/USB_DEVICE/Target -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src

clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src:
	-$(RM) ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.cyclo ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.d ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.o ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/usbd_hid.su

.PHONY: clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Class-2f-HID-2f-Src

