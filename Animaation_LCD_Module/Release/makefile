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
Animaation_LCD_Module.lss \

FLASH_IMAGE += \
Animaation_LCD_Module.hex \

EEPROM_IMAGE += \
Animaation_LCD_Module.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Animaation_LCD_Module.elf secondary-outputs

# Tool invocations
Animaation_LCD_Module.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Animaation_LCD_Module.map -mmcu=atmega32 -o "Animaation_LCD_Module.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Animaation_LCD_Module.lss: Animaation_LCD_Module.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Animaation_LCD_Module.elf  >"Animaation_LCD_Module.lss"
	@echo 'Finished building: $@'
	@echo ' '

Animaation_LCD_Module.hex: Animaation_LCD_Module.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Animaation_LCD_Module.elf  "Animaation_LCD_Module.hex"
	@echo 'Finished building: $@'
	@echo ' '

Animaation_LCD_Module.eep: Animaation_LCD_Module.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Animaation_LCD_Module.elf  "Animaation_LCD_Module.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Animaation_LCD_Module.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Animaation_LCD_Module.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Animaation_LCD_Module.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
