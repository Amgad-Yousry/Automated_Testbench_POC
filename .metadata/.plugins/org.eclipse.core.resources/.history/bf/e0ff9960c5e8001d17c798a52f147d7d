################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 12
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Generated_Code/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/clock/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
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
panel_control.elf \

EXECUTABLES_QUOTED += \
"panel_control.elf" \

EXECUTABLES_OS_FORMAT += \
panel_control.elf \

SECONDARY_SIZE += \
panel_control.siz \

SECONDARY_SIZE_QUOTED += \
"panel_control.siz" \

SECONDARY_SIZE_OS_FORMAT += \
panel_control.siz \


# All Target
all: warning-messages explicit-dependencies panel_control.elf secondary-outputs

# Tool invocations
panel_control.elf: $(OBJS) C:/Users/amgad/Downloads/nx/panel_control/Project_Settings/Linker_Files/S32K144_64_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #13 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "panel_control.elf" "@panel_control.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

panel_control.siz: $(EXECUTABLES)
	@echo 'Executing target #14 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*/*/*/*.d ./*/*/*/*/*/*/*.d ./*/*/*/*.d  ./*/*.o ./*/*/*/*/*/*.o ./*/*/*/*/*/*/*.o ./*/*/*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

