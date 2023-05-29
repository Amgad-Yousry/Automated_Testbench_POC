################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
<<<<<<<< HEAD:TestBench/.metadata/.plugins/org.eclipse.core.resources/.history/10/310581519cf8001d14f5829ff431c948
C_SRCS_QUOTED += \
"../Sources/helper_functions.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/helper_functions.c \
../Sources/main.c \

OBJS_OS_FORMAT += \
./Sources/helper_functions.o \
./Sources/main.o \

C_DEPS_QUOTED += \
"./Sources/helper_functions.d" \
"./Sources/main.d" \

OBJS += \
./Sources/helper_functions.o \
./Sources/main.o \

OBJS_QUOTED += \
"./Sources/helper_functions.o" \
"./Sources/main.o" \

C_DEPS += \
./Sources/helper_functions.d \
./Sources/main.d \


# Each subdirectory must supply rules for building sources it contributes
Sources/helper_functions.o: ../Sources/helper_functions.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/helper_functions.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "Sources/helper_functions.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
========
C_SRCS += \
D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/devices/startup.c 

OBJS += \
./SDK/platform/devices/startup.o 

C_DEPS += \
./SDK/platform/devices/startup.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/startup.o: D:/Program\ Files\ (x86)/S32DS/software/S32SDK_S32K1xx_RTM_3.0.0/platform/devices/startup.c
	@echo 'Building file: $<'
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/SDK/platform/devices/subdir.mk
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/devices/startup.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


