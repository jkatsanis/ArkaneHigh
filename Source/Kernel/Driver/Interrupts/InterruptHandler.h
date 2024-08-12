#pragma once

#include "Types.h"
#include "IO.h"
#include "TextRenderer.h"
#include "PIC.h"
#include "ISRHandler.h"

#define IDT_MAX_DESCRIPTORS 256

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

namespace Arkn
{
    class InterruptHandler
    {
    private:
        void IDTSetDescriptor(uint8_t vector, void* isr, uint8_t flags);
        void IDTInit();

        IDTEntry idt[IDT_MAX_DESCRIPTORS];
        IDTR idtr;

    public:
        InterruptHandler() = default;

        void Init();   
    };

} 
