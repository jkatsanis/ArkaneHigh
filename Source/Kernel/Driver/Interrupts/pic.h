#pragma once

#include "IO.h"

#define PIC_EOI     0x20
#define PIC1        0x20    
#define PIC2        0xA0   
#define ICW1        0x11    
#define ICW4        0x01   
#define PIC1_DATA	(PIC1+1)
#define PIC2_DATA	(PIC2+1)

namespace Arkn
{
    class PIC
    {
    private:
        static unsigned short int ocw1;

    public:
        PIC();

        static void Remap(int pic1, int pic2);
        static void EnableIrq(int irq);
        static void DisableIrq(int irq);
        static void SendEoi(int irq);
    };
}