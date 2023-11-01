#@copyright : prebared by Salah Soliman (Learn In Depth)

CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
C_files_dir = ../C_files/
SRC = $(wildcard $(C_files_dir)*.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=learn-in-depth




all: $(Project_name).bin
	@echo "==========Successfully Build=========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all :
	rm -rf *.o $(C_files_dir)*.o *.elf *.bin *.map *~
	@echo "all output build files are removed"
clean:
	rm -rf *.o $(C_files_dir)*.o *~ 
	@echo "all OBJ files are removed"
	

