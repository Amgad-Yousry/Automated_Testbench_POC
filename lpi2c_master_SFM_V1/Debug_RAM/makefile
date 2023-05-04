################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 21
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Generated_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/clock/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/lpi2c/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include Sources/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lpi2c_master_s32k144kl.elf \

EXECUTABLES_QUOTED += \
"lpi2c_master_s32k144kl.elf" \

EXECUTABLES_OS_FORMAT += \
lpi2c_master_s32k144kl.elf \

SECONDARY_SIZE += \
lpi2c_master_s32k144kl.siz \

SECONDARY_SIZE_QUOTED += \
"lpi2c_master_s32k144kl.siz" \

SECONDARY_SIZE_OS_FORMAT += \
lpi2c_master_s32k144kl.siz \


# All Target
all: warning-messages explicit-dependencies lpi2c_master_s32k144kl.elf secondary-outputs

# Tool invocations
lpi2c_master_s32k144kl.elf: $(OBJS) C:/NXP/S32DS_ARM_v2.0/S32DS/S32SDK_S32K14x_EAR_0.8.6/platform/devices/S32K144/linker/gcc/S32K144_64_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #22 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "lpi2c_master_s32k144kl.elf" "@lpi2c_master_s32k144kl.args"  $(USER_OBJS_QUOTED) 
	@echo 'Finished building target: $@'
	@echo ' '

lpi2c_master_s32k144kl.siz: $(EXECUTABLES)
	@echo 'Executing target #23 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*/*.d ./*/*/*/*/*/*.d ./*/*/*/*/*/*/*.d  ./*/*.o ./*/*/*/*.o ./*/*/*/*/*/*.o ./*/*/*/*/*/*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

