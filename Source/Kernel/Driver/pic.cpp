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

/* enable_irq()
 * sends command to PIC to enable an IRQ
 */
void enable_irq(int irq)
{
   ocw1 &= ~(1 << irq);   /* enable propriate bit with shifting to left
               invert the thing to enable the interrupt
               use AND operation to leave the other bits
               as they are
             */
   if (irq < 8)
      outb(PIC1 + 1, ocw1&0xFF);   /* AND with 0xFF to clear the high 8 
                       bits because we send to PIC1
                   */
   else
      outb(PIC2 + 1, ocw1 >> 8);   /* move high 8 bits to low 8 bits
                     since we send to PIC2
                   */
}

/* disable_irq()
 * sends a command to PIC to disable an IRQ
 */
void disable_irq(int irq)
{
   ocw1 |= (1 << irq);   /* shift left to disable the propriate bit
               OR to not change the mask
             */

   if (irq < 8)
      outb(PIC1 + 1, ocw1&0xFF);   /* AND with 0xFF to clear the
                     high 8 bits since we send to PIC1
                   */
   else
      outb(PIC2 + 1, ocw1 >> 8);   /* move high 8 bits to low 8 bits since
                     we send to PIC2
                   */
}

/* send_eoi()
 * sends a EOI to the PICs involved in the IRQ operation
 */
void send_eoi(int irq)
{
   if (irq > 7)
      outb(PIC2, 0x20);
   outb(PIC1, 0x20);
}