################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

C_DEPS += \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 

OBJS += \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.o Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.su Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.cyclo: ../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.c Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Core/Repo/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Core/Repo/USB_DEVICE/App -I../Core/Repo/USB_DEVICE/Target -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src:
	-$(RM) ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.cyclo ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.su ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.cyclo ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.su ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.cyclo ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o ./Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.su

.PHONY: clean-Core-2f-Repo-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

