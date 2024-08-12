#include "idt.h"

// Define IDT and IDTR
static IDTEntry idt[IDT_MAX_DESCRIPTORS];
static IDTR idtr;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    IDTEntry* descriptor = &idt[vector];

    descriptor->isr_low        = (uint64_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->ist            = 0;
    descriptor->attributes     = flags;
    descriptor->isr_mid        = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->isr_high       = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved       = 0;
}

void keyboard_isr_handler() {
    asm("cli");

    uint8_t scan_code = IO::Inb(0x60); // Read scan code from keyboard data port
    register int i;

    // Call your function to handle the key press
    TextRenderer::WriteLine("Mann");

    // Send EOI (End of Interrupt) to PICs
    send_eoi(1);

   int scan = inb(0x60);
   i = inb(0x61);
   outb(0x61, i|0x80);
   outb(0x61, i);
   send_eoi(1); 
      asm("sti");

}

void idt_init() {
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)(sizeof(IDTEntry) * IDT_MAX_DESCRIPTORS - 1);

    // Directly set ISR handlers in the IDT
    // Set up the keyboard ISR (IRQ1) at vector 33
    idt_set_descriptor(0x21 , (void*)keyboard_isr_handler, 0x8E);
    // Continue with other handlers as needed

    __asm__ volatile ("lidt %0" : : "m"(idtr)); // Load the new IDT
    __asm__ volatile ("sti"); // Set the interrupt flag

}


void init_idt() {
   remap_pics(0x20, 0x28);

   asm("cli");
   disable_irq(0);
   enable_irq(1);

   idt_init();
}
