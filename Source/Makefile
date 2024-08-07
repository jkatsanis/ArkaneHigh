OS_NAME := ArkaneOS
RELEASE_DIR := ../Bin/Release
DEBUG_DIR := ../Bin/Debug
INCLUDE := -IBoot Boot/Bootloader.asm

# RELEASE

compile: 
	rm -r ${RELEASE_DIR}
	mkdir ${RELEASE_DIR}

	./Build.sh Release
	@echo Compiling assembly...
	nasm -f bin $(INCLUDE) -o $(RELEASE_DIR)/Bootloader.bin
	nasm Kernel/Asm/KernelEntry.asm -f elf64 -o $(RELEASE_DIR)/KernelEntry.o
	nasm Kernel/Asm/Zeros.asm -f bin -o $(RELEASE_DIR)/Zeros.bin
	@echo ================

	@echo Linking object files....
	x86_64-elf-ld -o $(RELEASE_DIR)/FullKernel.bin -T linker.ld $(RELEASE_DIR)/*.o --oformat binary
	@echo ================
	
	@echo Creating the final binary...
	cat ${RELEASE_DIR}/Bootloader.bin ${RELEASE_DIR}/FullKernel.bin $(RELEASE_DIR)/Zeros.bin > ${RELEASE_DIR}/ArkaneOS.bin
	@echo ================
	@echo OS build complete

run:
	qemu-system-x86_64 -drive format=raw,file=$(RELEASE_DIR)/$(OS_NAME).bin -display curses

# DEBUG

compile_debug:
	rm -r ${DEBUG_DIR}
	mkdir ${DEBUG_DIR}

	./Build.sh Debug
	@echo Compiling assembly...
	nasm -f bin $(INCLUDE) -g -o $(DEBUG_DIR)/Bootloader.bin
	nasm Kernel/Asm/KernelEntry.asm -f elf64 -g -o $(DEBUG_DIR)/KernelEntry.o
	nasm Kernel/Asm/Zeros.asm -f bin -g -o $(DEBUG_DIR)/Zeros.bin
	@echo ================

	@echo Linking object files....
	x86_64-elf-ld -o $(DEBUG_DIR)/FullKernel.bin -T linker.ld $(DEBUG_DIR)/KernelEntry.o $(DEBUG_DIR)/Kernel.o --oformat binary
	@echo ================
	
	@echo Creating the final binary...
	cat ${DEBUG_DIR}/Bootloader.bin ${DEBUG_DIR}/FullKernel.bin $(DEBUG_DIR)/Zeros.bin > ${DEBUG_DIR}/ArkaneOS.bin
	@echo ================
	@echo OS build complete

run_debug: 
	qemu-system-x86_64 -s -S -hda $(DEBUG_DIR)/$(OS_NAME).bin -display curses

# CLEAN

clean: 
	rm -f ../Bin/Debug/*.bin
	rm -f ../Bin/Release/*.bin


