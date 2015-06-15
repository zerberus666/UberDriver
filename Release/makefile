################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MotorDriver.lss \

FLASH_IMAGE += \
MotorDriver.hex \

EEPROM_IMAGE += \
MotorDriver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: MotorDriver.elf secondary-outputs

# Tool invocations
MotorDriver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MotorDriver.map -mmcu=attiny2313 -o "MotorDriver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MotorDriver.lss: MotorDriver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MotorDriver.elf  >"MotorDriver.lss"
	@echo 'Finished building: $@'
	@echo ' '

MotorDriver.hex: MotorDriver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MotorDriver.elf  "MotorDriver.hex"
	@echo 'Finished building: $@'
	@echo ' '

MotorDriver.eep: MotorDriver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex MotorDriver.elf  "MotorDriver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MotorDriver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny2313 MotorDriver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MotorDriver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
