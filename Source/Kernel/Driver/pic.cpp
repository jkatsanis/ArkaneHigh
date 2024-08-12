#include "pic.h"

unsigned short int ocw1 = 0xFFFF; 

void remap_pics(int pic1, int pic2)
{
  uint8_t pic_1_mask, pic_2_mask;

    pic_1_mask = inb(PIC1_DATA);
    pic_2_mask = inb(PIC2_DATA);

    outb(PIC1, 0x11);
    io_wait();
    outb(PIC2, 0x11);
    io_wait();

    outb(PIC1_DATA, pic1);
    io_wait();
    outb(PIC2_DATA, pic2);
    io_wait();
    
    outb(PIC1_DATA, 0x4);
    io_wait();
    outb(PIC2_DATA, 0x2);
    io_wait();
   
    outb(PIC1_DATA, 0x1); 
    io_wait();
    outb(PIC2_DATA, 0x1); 
    io_wait();

    outb(PIC1_DATA, pic_1_mask);
    outb(PIC2_DATA, pic_2_mask);
}


void enable_irq(int irq)
{
   ocw1 &= ~(1 << irq);  
   if (irq < 8)
      outb(PIC1 + 1, ocw1&0xFF);   
   else
      outb(PIC2 + 1, ocw1 >> 8);  
}

void disable_irq(int irq)
{
   ocw1 |= (1 << irq);   
   if (irq < 8)
      outb(PIC1 + 1, ocw1&0xFF);   
   else
      outb(PIC2 + 1, ocw1 >> 8);   
}

void send_eoi(int irq)
{
   if (irq > 7)
      outb(PIC2, 0x20);
   outb(PIC1, 0x20);
}