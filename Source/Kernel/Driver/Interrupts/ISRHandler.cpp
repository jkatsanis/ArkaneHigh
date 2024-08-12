#include "ISRHandler.h"

namespace Arkn
{
    void ISRKeyboardHandler()
    {
        asm("cli");

        uint8_t scan_code = IO::Inb(0x60); // Read scan code from keyboard data port

        // Call your function to handle the key press
        nKeyboardDriver_ptr->OnKeyboardPress(5);

        // Send EOI (End of Interrupt) to PICs
        PIC::SendEoi(1);

        asm("sti");
    }
}