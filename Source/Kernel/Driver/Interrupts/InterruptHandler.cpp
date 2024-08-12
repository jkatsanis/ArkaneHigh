#include "InterruptHandler.h"

void Arkn::InterruptHandler::IDTSetDescriptor(uint8_t vector, void* isr, uint8_t flags) {
    IDTEntry* descriptor = &idt[vector];

    descriptor->isr_low        = (uint64_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->ist            = 0;
    descriptor->attributes     = flags;
    descriptor->isr_mid        = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->isr_high       = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved       = 0;
}

void Arkn::InterruptHandler::IDTInit() {
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)(sizeof(IDTEntry) * IDT_MAX_DESCRIPTORS - 1);

    // Directly set ISR handlers in the IDT
    // Set up the keyboard ISR (IRQ1) at vector 33
    IDTSetDescriptor(0x21 , (void*)keyboard_isr_handler, 0x8E);
    // Continue with other handlers as needed

    __asm__ volatile ("lidt %0" : : "m"(idtr)); // Load the new IDT
}


void Arkn::InterruptHandler::Init() 
{
    // Disable interrupts
    asm("cli"); 

    PIC::Remap(0x20, 0x28);

    PIC::EnableIrq(1);

    IDTInit();

    // Enable interrupts
    asm("sti"); 
}
