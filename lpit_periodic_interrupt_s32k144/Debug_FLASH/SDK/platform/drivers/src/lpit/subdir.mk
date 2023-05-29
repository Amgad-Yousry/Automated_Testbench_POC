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
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/lpit/lpit_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


