ENTRY(kernel_entry)

SECTIONS
{
    /* Set the start address for the code */
    . = 0x8000;

    /* The .text section contains executable code */
    .text : {
        *(.text)       /* Collect all .text sections from object files */
    }

    /* The .data section contains initialized global variables */
    .data : {
        *(.data)       /* Collect all .data sections from object files */
    }

    /* The .bss section contains uninitialized global variables */
    .bss : {
        *(.bss)        /* Collect all .bss sections from object files */
    }

    /* End of the program */
    . = ALIGN(0x1000);
}
