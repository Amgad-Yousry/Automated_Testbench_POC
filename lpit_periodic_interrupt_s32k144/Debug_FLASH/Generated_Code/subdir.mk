################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/clockMan1.c \
../Generated_Code/lpit1.c \
../Generated_Code/pin_mux.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/clockMan1.o \
./Generated_Code/lpit1.o \
./Generated_Code/pin_mux.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/clockMan1.d \
./Generated_Code/lpit1.d \
./Generated_Code/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
<<<<<<<< HEAD:TestBench/Trash/freemaster_s32k144/Debug_FLASH/Sources/subdir.mk
	@echo 'Executing target #39 $<'
========
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/Generated_Code/subdir.mk
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


