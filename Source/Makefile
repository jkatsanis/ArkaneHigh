OS_NAME := ArkaneOS
RELEASE_DIR := ../Bin/Release
DEBUG_DIR := ../Bin/Debug
INCLUDE := -IBoot Boot/Bootloader.asm

# RELEASE

compile: 
	rm -r ${RELEASE_DIR}
	mkdir ${RELEASE_DIR}

	nasm -f bin $(INCLUDE) -o $(RELEASE_DIR)/Bootloader.bin
	nasm Kernel/KernelEntry.asm -f elf -o $(RELEASE_DIR)/KernelEntry.o

	i686-elf-g++ -ffreestanding -c Kernel/Kernel.cpp -o $(RELEASE_DIR)/Kernel.o
	i686-elf-ld -o $(RELEASE_DIR)/FullKernel.bin -Ttext 0x8000 $(RELEASE_DIR)/KernelEntry.o $(RELEASE_DIR)/Kernel.o --oformat binary

	cat ${RELEASE_DIR}/Bootloader.bin ${RELEASE_DIR}/FullKernel.bin > ${RELEASE_DIR}/ArkaneOS.bin

run:
	qemu-system-x86_64 -drive format=raw,file=$(RELEASE_DIR)/$(OS_NAME).bin -display curses

# DEBUG

debug:
	make compile_debug
	make run_debug

compile_debug:
	nasm -f bin $(INCLUDE) -g -o $(DEBUG_DIR)/$(OS_NAME).bin

run_debug: 
	qemu-system-x86_64 -s -S -hda $(DEBUG_DIR)/$(OS_NAME).bin

run_gdb:
	gdb ../Bin/Debug/ArkaneOS.bin

# CLEAN

clean: 
	rm -f ../Bin/Debug/*.bin
	rm -f ../Bin/Release/*.bin


