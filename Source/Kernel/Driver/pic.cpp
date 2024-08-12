#include "pic.h"

unsigned short int ocw1 = 0xFFFF;   /* short int = 16 bits */

void remap_pics(int pic1, int pic2)
{
   /* send ICW1 */
   outb(PIC1, ICW1);
   outb(PIC2, ICW1);

   /* send ICW2 */
   outb(PIC1 + 1, pic1);   /* remap
   outb(PIC2 + 2, pic2);      pics */

   /* send ICW3 */
   outb(PIC1 + 1, 4);   /* IRQ2 -> connection to slave */
   outb(PIC2 + 1, 2);

   /* send ICW4 */
   outb(PIC1 + 1, ICW4);
   outb(PIC2 + 1, ICW4);

   /* disable all IRQs */
   outb(PIC1 + 1, 0xFF);
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