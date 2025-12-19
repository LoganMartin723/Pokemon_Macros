################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Repo/USB_DEVICE/App/usb_device.c \
../Core/Repo/USB_DEVICE/App/usbd_desc.c 

C_DEPS += \
./Core/Repo/USB_DEVICE/App/usb_device.d \
./Core/Repo/USB_DEVICE/App/usbd_desc.d 

OBJS += \
./Core/Repo/USB_DEVICE/App/usb_device.o \
./Core/Repo/USB_DEVICE/App/usbd_desc.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Repo/USB_DEVICE/App/%.o Core/Repo/USB_DEVICE/App/%.su Core/Repo/USB_DEVICE/App/%.cyclo: ../Core/Repo/USB_DEVICE/App/%.c Core/Repo/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Core/Repo/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Core/Repo/USB_DEVICE/App -I../Core/Repo/USB_DEVICE/Target -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Repo-2f-USB_DEVICE-2f-App

clean-Core-2f-Repo-2f-USB_DEVICE-2f-App:
	-$(RM) ./Core/Repo/USB_DEVICE/App/usb_device.cyclo ./Core/Repo/USB_DEVICE/App/usb_device.d ./Core/Repo/USB_DEVICE/App/usb_device.o ./Core/Repo/USB_DEVICE/App/usb_device.su ./Core/Repo/USB_DEVICE/App/usbd_desc.cyclo ./Core/Repo/USB_DEVICE/App/usbd_desc.d ./Core/Repo/USB_DEVICE/App/usbd_desc.o ./Core/Repo/USB_DEVICE/App/usbd_desc.su

.PHONY: clean-Core-2f-Repo-2f-USB_DEVICE-2f-App

