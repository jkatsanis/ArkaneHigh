#include "idt.h"

// Define IDT and IDTR
__attribute__((aligned(0x10))) static IDTEntry idt[IDT_MAX_DESCRIPTORS];
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
    TextRenderer::WriteLine("TROLLL");
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


void pic_remap() {
    // Save masks
    uint8_t master_mask = IO::Inb(0x21);
    uint8_t slave_mask = IO::Inb(0xA1);

    // Initialize Master PIC (ICW1)
    IO::Outb(0x20, 0x11);
    IO::Outb(0x21, 0x20);
    IO::Outb(0x21, 0x04);
    IO::Outb(0x21, 0x01);

    // Initialize Slave PIC (ICW1)
    IO::Outb(0xA0, 0x11);
    IO::Outb(0xA1, 0x28);
    IO::Outb(0xA1, 0x02);
    IO::Outb(0xA1, 0x01);

    // Restore saved masks
    IO::Outb(0x21, master_mask);
    IO::Outb(0xA1, slave_mask);
}


void keyboard_isr() {
    uint8_t scan_code = IO::Inb(0x60); // Read scan code from keyboard data port

    // Call your function to handle the key press
    on_keyboard_press(scan_code);

    // Send EOI (End of Interrupt) to PICs
    IO::Outb(0x20, 0x20);
    IO::Outb(0xA0, 0x20);
}

void init_idt() {
    pic_remap();
    idt_init();
}
