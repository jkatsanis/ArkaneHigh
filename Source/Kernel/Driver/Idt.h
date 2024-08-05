#pragma once

#include "Types.h"
#include "IO.h"

using namespace Arkn;

typedef struct {
	uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t	    ist;          // The IST in the TSS that the CPU will load into RSP; set to zero for now
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_mid;      // The higher 16 bits of the lower 32 bits of the ISR's address
	uint32_t    isr_high;     // The higher 32 bits of the ISR's address
	uint32_t    reserved;     // Set to zero
} __attribute__((packed)) idt_entry_t;

typedef struct {
	uint16_t	limit;
	uint64_t	base;
} __attribute__((packed)) idtr_t;

__attribute__((aligned(0x10))) 
static idt_entry_t idt[256]; // Create an array of IDT entries; aligned for performance
static idtr_t idtr;

void set_idt_entry(int index, void (*handler)(), uint16_t kernel_cs, uint8_t attributes) {
    uint64_t handler_addr = (uint64_t)handler;

    idt[index].isr_low = handler_addr & 0xFFFF;
    idt[index].kernel_cs = kernel_cs;
    idt[index].ist = 0;
    idt[index].attributes = attributes;
    idt[index].isr_mid = (handler_addr >> 16) & 0xFFFF;
    idt[index].isr_high = (handler_addr >> 32) & 0xFFFFFFFF;
    idt[index].reserved = 0;
}

void load_idt() {
    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint64_t)idt;

    __asm__ volatile ("lidt %0" : : "m"(idtr));
}

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_CMD (PIC1)
#define PIC1_DATA (PIC1 + 1)
#define PIC2_CMD (PIC2)
#define PIC2_DATA (PIC2 + 1)

void pic_remap() {
    // Save masks
    uint8_t mask1 = IO::Inb(PIC1_DATA);
    uint8_t mask2 = IO::Inb(PIC2_DATA);

    // Initialization sequence
    IO::Outb(PIC1_CMD, 0x11);
    IO::Outb(PIC2_CMD, 0x11);
    
    // ICW1: edge-triggered mode
    // ICW2: IRQ0-7 mapped to 0x20-0x27, IRQ8-15 mapped to 0x28-0x2F
    IO::Outb(PIC1_DATA, 0x20);
    IO::Outb(PIC2_DATA, 0x28);
    
    // ICW3: tells PIC1 there is a PIC2
    IO::Outb(PIC1_DATA, 0x04);
    IO::Outb(PIC2_DATA, 0x02);
    
    // ICW4: 8086 mode
    IO::Outb(PIC1_DATA, 0x01);
    IO::Outb(PIC2_DATA, 0x01);
    
    // Restore masks
    IO::Outb(PIC1_DATA, mask1);
    IO::Outb(PIC2_DATA, mask2);
}

void keyboard_isr() {
    uint8_t scan_code = IO::Inb(0x60); // Read scan code from keyboard data port
    
    // Call your function to handle the key press
    on_keyboard_press(scan_code);
    
    // Send EOI (End of Interrupt) to PICs
    IO::Outb(PIC1_CMD, 0x20);
    IO::Outb(PIC2_CMD, 0x20);
}

void on_keyboard_press(uint8_t scan_code) {
    // Handle the key press
}
