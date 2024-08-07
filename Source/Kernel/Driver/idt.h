#pragma once

#include "Types.h"
#include "IO.h"
#include "TextRenderer.h"

#define IDT_MAX_DESCRIPTORS 256

using namespace Arkn;

struct __attribute__((packed)) IDTEntry {
    uint16_t isr_low;
    uint16_t kernel_cs;
    uint8_t ist;
    uint8_t attributes;
    uint16_t isr_mid;
    uint32_t isr_high;
    uint32_t reserved;
};

struct __attribute__((packed)) IDTR {
    uint16_t limit;
    uint64_t base;
};

// Functions for IDT management
void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
void idt_init();
void pic_remap();
void keyboard_isr();
void on_keyboard_press(uint8_t scan_code);
void init_idt();