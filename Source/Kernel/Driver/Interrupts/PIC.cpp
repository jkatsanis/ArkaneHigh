#include "PIC.h"

unsigned short int Arkn::PIC::ocw1 = 0xFFFF;

void Arkn::PIC::Remap(int pic1, int pic2)
{
   uint8_t pic_1_mask, pic_2_mask;

   pic_1_mask = IO::Inb(PIC1_DATA);
   pic_2_mask = IO::Inb(PIC2_DATA);

   IO::Outb(PIC1, ICW1);
   IO::IoWait();
   IO::Outb(PIC2, ICW1);
   IO::IoWait();

   IO::Outb(PIC1_DATA, pic1);
   IO::IoWait();
   IO::Outb(PIC2_DATA, pic2);
   IO::IoWait();
    
   IO::Outb(PIC1_DATA, 0x4);
   IO::IoWait();
   IO::Outb(PIC2_DATA, 0x2);
   IO::IoWait();

   IO::Outb(PIC1_DATA, ICW4); 
   IO::IoWait();
   IO::Outb(PIC2_DATA, ICW4); 
   IO::IoWait();

   IO::Outb(PIC1_DATA, pic_1_mask);
   IO::Outb(PIC2_DATA, pic_2_mask);
}

void Arkn::PIC::EnableIrq(int irq)
{
   ocw1 &= ~(1 << irq);  
   if (irq < 8)
      IO::Outb(PIC1_DATA, ocw1 & 0xFF);   
   else
      IO::Outb(PIC2_DATA, ocw1 >> 8);  
}

void Arkn::PIC::DisableIrq(int irq)
{
   ocw1 |= (1 << irq);   
   if (irq < 8)
      IO::Outb(PIC1_DATA, ocw1 & 0xFF);   
   else
      IO::Outb(PIC2_DATA, ocw1 >> 8);   
}

void Arkn::PIC::SendEoi(int irq)
{
   if (irq > 7)
      IO::Outb(PIC2, PIC_EOI);
   IO::Outb(PIC1, PIC_EOI);
}