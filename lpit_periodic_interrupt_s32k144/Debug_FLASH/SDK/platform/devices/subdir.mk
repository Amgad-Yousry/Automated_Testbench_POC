################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/devices/startup.c 

OBJS += \
./SDK/platform/devices/startup.o 

C_DEPS += \
./SDK/platform/devices/startup.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/startup.o: D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/devices/startup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/devices/startup.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


