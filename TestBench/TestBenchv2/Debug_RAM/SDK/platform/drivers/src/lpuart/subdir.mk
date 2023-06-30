################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"D:/Program Files (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_driver.c" \
"D:/Program Files (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_hw_access.c" \
"D:/Program Files (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_irq.c" \

C_SRCS += \
D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_driver.c \
D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_hw_access.c \
D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_irq.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/lpuart/lpuart_driver.o \
./SDK/platform/drivers/src/lpuart/lpuart_hw_access.o \
./SDK/platform/drivers/src/lpuart/lpuart_irq.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/lpuart/lpuart_driver.d" \
"./SDK/platform/drivers/src/lpuart/lpuart_hw_access.d" \
"./SDK/platform/drivers/src/lpuart/lpuart_irq.d" \

OBJS += \
./SDK/platform/drivers/src/lpuart/lpuart_driver.o \
./SDK/platform/drivers/src/lpuart/lpuart_hw_access.o \
./SDK/platform/drivers/src/lpuart/lpuart_irq.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/lpuart/lpuart_driver.o" \
"./SDK/platform/drivers/src/lpuart/lpuart_hw_access.o" \
"./SDK/platform/drivers/src/lpuart/lpuart_irq.o" \

C_DEPS += \
./SDK/platform/drivers/src/lpuart/lpuart_driver.d \
./SDK/platform/drivers/src/lpuart/lpuart_hw_access.d \
./SDK/platform/drivers/src/lpuart/lpuart_irq.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/lpuart/lpuart_driver.o: D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/lpuart/lpuart_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "SDK/platform/drivers/src/lpuart/lpuart_driver.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/lpuart/lpuart_hw_access.o: D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_hw_access.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/lpuart/lpuart_hw_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "SDK/platform/drivers/src/lpuart/lpuart_hw_access.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/lpuart/lpuart_irq.o: D:/Program\ Files\ (x86)/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/lpuart/lpuart_irq.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/lpuart/lpuart_irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "SDK/platform/drivers/src/lpuart/lpuart_irq.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


