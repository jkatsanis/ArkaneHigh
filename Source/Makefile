OS_NAME := ArkaneOS
RELEASE_DIR := ../Bin/Release
DEBUG_DIR := ../Bin/Debug
INCLUDE := -IBoot Boot/Bootloader.asm

# RELEASE

compile: 
	rm -r ${RELEASE_DIR}
	mkdir ${RELEASE_DIR}

	nasm -f bin $(INCLUDE) -o $(RELEASE_DIR)/Bootloader.bin

# Build C++ here
	./Build.sh

	nasm Kernel/Asm/KernelEntry.asm -f elf -o $(RELEASE_DIR)/KernelEntry.o
	i686-elf-ld -o $(RELEASE_DIR)/FullKernel.bin -Ttext 0x8000 $(RELEASE_DIR)/KernelEntry.o $(RELEASE_DIR)/Kernel.o --oformat binary

	nasm Kernel/Asm/Zeros.asm -f bin -o $(RELEASE_DIR)/Zeros.bin

	cat ${RELEASE_DIR}/Bootloader.bin ${RELEASE_DIR}/FullKernel.bin $(RELEASE_DIR)/Zeros.bin > ${RELEASE_DIR}/ArkaneOS.bin

run:
	qemu-system-x86_64 -drive format=raw,file=$(RELEASE_DIR)/$(OS_NAME).bin -display curses

# DEBUG

debug:
	make compile_debug
	make run_debug

compile_debug:
	rm -r ${DEBUG_DIR}
	mkdir ${DEBUG_DIR}

	nasm -f bin $(INCLUDE) -g -o $(DEBUG_DIR)/Bootloader.bin

# Build C++ here
	./BuildDebug.sh

	nasm Kernel/Asm/KernelEntry.asm -f elf -g -o $(DEBUG_DIR)/KernelEntry.o
	i686-elf-ld -o $(DEBUG_DIR)/FullKernel.bin -Ttext 0x8000 $(DEBUG_DIR)/KernelEntry.o $(DEBUG_DIR)/Kernel.o --oformat binary

	nasm Kernel/Asm/Zeros.asm -f bin -g -o $(DEBUG_DIR)/Zeros.bin

	cat ${DEBUG_DIR}/Bootloader.bin ${DEBUG_DIR}/FullKernel.bin $(DEBUG_DIR)/Zeros.bin > ${DEBUG_DIR}/ArkaneOS.bin

run_debug: 
	qemu-system-x86_64 -s -S -hda $(DEBUG_DIR)/$(OS_NAME).bin -display curses

# CLEAN

clean: 
	rm -f ../Bin/Debug/*.bin
	rm -f ../Bin/Release/*.bin


