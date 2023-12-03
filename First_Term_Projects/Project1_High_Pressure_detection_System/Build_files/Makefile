CC = arm-none-eabi-
CFLAGS = -mthumb -mcpu=cortex-m3 -gdwarf-2
INCS = -I .
LIBS =
C_files_dir = ../C_files/
C_files_dir2 = ../C_files/driver/
C_files_dir3 = ../Build_files/
SRC = $(wildcard $(C_files_dir)*.c) $(wildcard $(C_files_dir2)*.c) $(wildcard $(C_files_dir3)*.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = HPD_system_Cortex_M3

all: $(Project_name).bin
	@echo "==========Successfully Build=========="

hex: $(Project_name).hex

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

$(Project_name).hex: $(Project_name).elf
	$(CC)objcopy.exe -O ihex $< $@

clean_all:
	rm -rf *.o $(C_files_dir)*.o $(C_files_dir2)*.o $(C_files_dir3)*.o *.elf *.hex *.bin *.map *~
	@echo "all output build files are removed"

clean:
	rm -rf *.elf *.bin *.map *.hex *~
	@echo "all linked files are removed"