#pragma once

#include "KeyboardDriver.h"

namespace Arkn
{
    // A pointer o the keyboard driver from the Kernel class instance. gets used in the idt
    static KeyboardDriver* nKeyboardDriver_ptr = nullptr;
}