[bits 64]
[extern main]

global KernelEntry ; Gets set in the linker script :D 

KernelEntry:
    call main
    jmp $