#pragma once

#include "io.h"

/* Constants for PIC I/O ports */
#define PIC1        0x20    /* Master PIC command port */
#define PIC2        0xA0    /* Slave PIC command port */
#define ICW1        0x11    /* Initialization Command Word 1 */
#define ICW4        0x01    /* Initialization Command Word 4 */

/* Function prototypes */
void remap_pics(int pic1, int pic2);
void enable_irq(int irq);
void disable_irq(int irq);
void send_eoi(int irq);
