################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2.0/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/clock/clock_manager.c" \

C_SRCS += \
C:/NXP/S32DS_ARM_v2.0/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/clock/clock_manager.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/clock/clock_manager.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/clock/clock_manager.d" \

OBJS += \
./SDK/platform/drivers/src/clock/clock_manager.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/clock/clock_manager.o" \

C_DEPS += \
./SDK/platform/drivers/src/clock/clock_manager.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/clock/clock_manager.o: C:/NXP/S32DS_ARM_v2.0/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/drivers/src/clock/clock_manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/clock/clock_manager.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "SDK/platform/drivers/src/clock/clock_manager.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


