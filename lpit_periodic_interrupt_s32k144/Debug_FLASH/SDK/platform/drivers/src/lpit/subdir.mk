################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/drivers/src/lpit/lpit_driver.c 

OBJS += \
./SDK/platform/drivers/src/lpit/lpit_driver.o 

C_DEPS += \
./SDK/platform/drivers/src/lpit/lpit_driver.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/lpit/lpit_driver.o: D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/drivers/src/lpit/lpit_driver.c
	@echo 'Building file: $<'
<<<<<<<< HEAD:TestBench/Trash/freemaster_s32k144/Debug_RAM/Sources/subdir.mk
	@echo 'Executing target #39 $<'
========
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/SDK/platform/drivers/src/lpit/subdir.mk
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/lpit/lpit_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


