ENTRY(KernelEntry) /* Calls the KernelEntry label */

SECTIONS
{
    . = 0x8000;

    .text : {
        *(.text)      
    }

    .data : {
        *(.data)       
    }

    .bss : {
        *(.bss)      
    }

    /* End of the program */
    . = ALIGN(0x1000);
}
