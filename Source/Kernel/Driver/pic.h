#pragma once

#include "io.h"

#define PIC_EOI     0x20
#define PIC1        0x20    
#define PIC2        0xA0   
#define ICW1        0x11    
#define ICW4        0x01   
#define PIC1_DATA	(PIC1+1)
#define PIC2_DATA	(PIC2+1)

void remap_pics(int pic1, int pic2);
void enable_irq(int irq);
void disable_irq(int irq);
void send_eoi(int irq);
