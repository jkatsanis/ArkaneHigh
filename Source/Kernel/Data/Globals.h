#pragma once

#include "KeyboardDriver.h"

/// @brief Kernel systems. Can be used by everyone. lol
namespace Arkn
{
    class Globals
    {
    public:
        // A pointer o the keyboard driver from the Kernel class instance. gets used in the idt
        static KeyboardDriver* s_KeyboardDriver_ptr ;

        static bool handling ;
    };

}