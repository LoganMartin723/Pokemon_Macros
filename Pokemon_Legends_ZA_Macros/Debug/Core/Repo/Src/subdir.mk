################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Repo/Src/ButtonDriver.cpp \
../Core/Repo/Src/InputDriver.cpp \
../Core/Repo/Src/Macros.cpp \
../Core/Repo/Src/SSD1306_SPI_Driver.cpp \
../Core/Repo/Src/StateDriver.cpp \
../Core/Repo/Src/SwitchDriver.cpp \
../Core/Repo/Src/cpp_main.cpp \
../Core/Repo/Src/queue.cpp 

C_SRCS += \
../Core/Repo/Src/ns_joystick.c 

C_DEPS += \
./Core/Repo/Src/ns_joystick.d 

OBJS += \
./Core/Repo/Src/ButtonDriver.o \
./Core/Repo/Src/InputDriver.o \
./Core/Repo/Src/Macros.o \
./Core/Repo/Src/SSD1306_SPI_Driver.o \
./Core/Repo/Src/StateDriver.o \
./Core/Repo/Src/SwitchDriver.o \
./Core/Repo/Src/cpp_main.o \
./Core/Repo/Src/ns_joystick.o \
./Core/Repo/Src/queue.o 

CPP_DEPS += \
./Core/Repo/Src/ButtonDriver.d \
./Core/Repo/Src/InputDriver.d \
./Core/Repo/Src/Macros.d \
./Core/Repo/Src/SSD1306_SPI_Driver.d \
./Core/Repo/Src/StateDriver.d \
./Core/Repo/Src/SwitchDriver.d \
./Core/Repo/Src/cpp_main.d \
./Core/Repo/Src/queue.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Repo/Src/%.o Core/Repo/Src/%.su Core/Repo/Src/%.cyclo: ../Core/Repo/Src/%.cpp Core/Repo/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Core/Repo/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Core/Repo/USB_DEVICE/App -I../Core/Repo/USB_DEVICE/Target -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Repo/Src/%.o Core/Repo/Src/%.su Core/Repo/Src/%.cyclo: ../Core/Repo/Src/%.c Core/Repo/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Core/Repo/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Core/Repo/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Core/Repo/USB_DEVICE/App -I../Core/Repo/USB_DEVICE/Target -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Repo-2f-Src

clean-Core-2f-Repo-2f-Src:
	-$(RM) ./Core/Repo/Src/ButtonDriver.cyclo ./Core/Repo/Src/ButtonDriver.d ./Core/Repo/Src/ButtonDriver.o ./Core/Repo/Src/ButtonDriver.su ./Core/Repo/Src/InputDriver.cyclo ./Core/Repo/Src/InputDriver.d ./Core/Repo/Src/InputDriver.o ./Core/Repo/Src/InputDriver.su ./Core/Repo/Src/Macros.cyclo ./Core/Repo/Src/Macros.d ./Core/Repo/Src/Macros.o ./Core/Repo/Src/Macros.su ./Core/Repo/Src/SSD1306_SPI_Driver.cyclo ./Core/Repo/Src/SSD1306_SPI_Driver.d ./Core/Repo/Src/SSD1306_SPI_Driver.o ./Core/Repo/Src/SSD1306_SPI_Driver.su ./Core/Repo/Src/StateDriver.cyclo ./Core/Repo/Src/StateDriver.d ./Core/Repo/Src/StateDriver.o ./Core/Repo/Src/StateDriver.su ./Core/Repo/Src/SwitchDriver.cyclo ./Core/Repo/Src/SwitchDriver.d ./Core/Repo/Src/SwitchDriver.o ./Core/Repo/Src/SwitchDriver.su ./Core/Repo/Src/cpp_main.cyclo ./Core/Repo/Src/cpp_main.d ./Core/Repo/Src/cpp_main.o ./Core/Repo/Src/cpp_main.su ./Core/Repo/Src/ns_joystick.cyclo ./Core/Repo/Src/ns_joystick.d ./Core/Repo/Src/ns_joystick.o ./Core/Repo/Src/ns_joystick.su ./Core/Repo/Src/queue.cyclo ./Core/Repo/Src/queue.d ./Core/Repo/Src/queue.o ./Core/Repo/Src/queue.su

.PHONY: clean-Core-2f-Repo-2f-Src

