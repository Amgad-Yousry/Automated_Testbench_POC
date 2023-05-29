################################################################################
# Automatically-generated file. Do not edit!
################################################################################

<<<<<<<< HEAD:TestBench/.metadata/.plugins/org.eclipse.core.resources/.history/0/b04e5461a9f8001d14f5829ff431c948
#Progress monitor hint: 18
first : all
========
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/makefile
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
<<<<<<<< HEAD:TestBench/.metadata/.plugins/org.eclipse.core.resources/.history/0/b04e5461a9f8001d14f5829ff431c948
-include subdir.mk
-include Generated_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/platform/drivers/src/adc/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/clock/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/pdb/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include Sources/subdir.mk
========
-include Sources/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/platform/drivers/src/lpit/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/devices/S32K144/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Generated_Code/subdir.mk
-include subdir.mk
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/makefile
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
<<<<<<<< HEAD:TestBench/.metadata/.plugins/org.eclipse.core.resources/.history/0/b04e5461a9f8001d14f5829ff431c948
EXECUTABLES += \
pdb_periodic_interrupt_s32k144.elf \

EXECUTABLES_QUOTED += \
"pdb_periodic_interrupt_s32k144.elf" \

EXECUTABLES_OS_FORMAT += \
pdb_periodic_interrupt_s32k144.elf \

SECONDARY_SIZE += \
pdb_periodic_interrupt_s32k144.siz \

SECONDARY_SIZE_QUOTED += \
"pdb_periodic_interrupt_s32k144.siz" \

SECONDARY_SIZE_OS_FORMAT += \
pdb_periodic_interrupt_s32k144.siz \


# All Target
all: warning-messages explicit-dependencies pdb_periodic_interrupt_s32k144.elf secondary-outputs

# Tool invocations
pdb_periodic_interrupt_s32k144.elf: $(OBJS) C:/NXP/S32DS_ARM_v2.0/S32DS/S32SDK_S32K14x_EAR_0.8.4/platform/devices/S32K144/linker/gcc/S32K144_64_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #19 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "pdb_periodic_interrupt_s32k144.elf" "@pdb_periodic_interrupt_s32k144.args"  $(USER_OBJS_QUOTED) 
	@echo 'Finished building target: $@'
	@echo ' '

pdb_periodic_interrupt_s32k144.siz: $(EXECUTABLES)
	@echo 'Executing target #20 $@'
========
SECONDARY_SIZE += \
lpit_periodic_interrupt_s32k144.siz \


# All Target
all: lpit_periodic_interrupt_s32k144.elf secondary-outputs

# Tool invocations
lpit_periodic_interrupt_s32k144.elf: $(OBJS) D:\Program\ Files\ (x86)\S32DS\software\S32SDK_S32K1xx_RTM_3.0.0\platform\devices\S32K144\linker\gcc\S32K144_64_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "lpit_periodic_interrupt_s32k144.elf" "@lpit_periodic_interrupt_s32k144.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

lpit_periodic_interrupt_s32k144.siz: lpit_periodic_interrupt_s32k144.elf
>>>>>>>> f76ecdfe66d4711ffc38d5183c63b21726cd4a25:lpit_periodic_interrupt_s32k144/Debug_FLASH/makefile
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley lpit_periodic_interrupt_s32k144.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
