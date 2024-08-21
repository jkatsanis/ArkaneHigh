#include "ISRHandler.h"

namespace Arkn
{
    void ISRKeyboardHandler()
    {
        Globals::handling = true;
        asm("cli");

        uint8_t scan_code = IO::Inb(0x60); // Read scan code from keyboard data port
        Globals::s_KeyboardDriver_ptr->Buffer = scan_code;


        // Send EOI (End of Interrupt) to PICs
        PIC::SendEoi(1);

        asm("sti");
        Globals::handling = false;

    }
}