#@copyright : prebared by Salah Soliman (Learn In Depth)

CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=unit3_lab4_cortexM4




all: $(Project_name).bin
	@echo "==========Successfully Build=========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all :
	rm -rf *.o *.elf *.axf *.bin *.map *~
	@echo "all output build files are removed"
clean:
	rm -rf *.elf *.bin *.axf *.map *~ 
	@echo "all linled files are removed"
	

