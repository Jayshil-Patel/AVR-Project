################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../18ec068_interfaced_keypad_lcd_final.c \
../lcd_4_bit.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
18ec068_interfaced_keypad_lcd_final.o \
lcd_4_bit.o

OBJS_AS_ARGS +=  \
18ec068_interfaced_keypad_lcd_final.o \
lcd_4_bit.o

C_DEPS +=  \
18ec068_interfaced_keypad_lcd_final.d \
lcd_4_bit.d

C_DEPS_AS_ARGS +=  \
18ec068_interfaced_keypad_lcd_final.d \
lcd_4_bit.d

OUTPUT_FILE_PATH +=18ec068_interfaced_keypad_lcd_final.elf

OUTPUT_FILE_PATH_AS_ARGS +=18ec068_interfaced_keypad_lcd_final.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./18ec068_interfaced_keypad_lcd_final.o: .././18ec068_interfaced_keypad_lcd_final.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -I"D:\softwares\Atmel\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\softwares\Atmel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./lcd_4_bit.o: .././lcd_4_bit.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -I"D:\softwares\Atmel\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\softwares\Atmel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="18ec068_interfaced_keypad_lcd_final.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "D:\softwares\Atmel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "18ec068_interfaced_keypad_lcd_final.elf" "18ec068_interfaced_keypad_lcd_final.hex"
	"D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "18ec068_interfaced_keypad_lcd_final.elf" "18ec068_interfaced_keypad_lcd_final.eep" || exit 0
	"D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "18ec068_interfaced_keypad_lcd_final.elf" > "18ec068_interfaced_keypad_lcd_final.lss"
	"D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "18ec068_interfaced_keypad_lcd_final.elf" "18ec068_interfaced_keypad_lcd_final.srec"
	"D:\softwares\Atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "18ec068_interfaced_keypad_lcd_final.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "18ec068_interfaced_keypad_lcd_final.elf" "18ec068_interfaced_keypad_lcd_final.a" "18ec068_interfaced_keypad_lcd_final.hex" "18ec068_interfaced_keypad_lcd_final.lss" "18ec068_interfaced_keypad_lcd_final.eep" "18ec068_interfaced_keypad_lcd_final.map" "18ec068_interfaced_keypad_lcd_final.srec" "18ec068_interfaced_keypad_lcd_final.usersignatures"
	