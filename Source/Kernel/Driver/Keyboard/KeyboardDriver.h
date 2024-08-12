#pragma once

#include "Types.h"
#include "TextRenderer.h"

namespace Arkn
{
    class KeyboardDriver
    {
    public:
        void OnKeyboardPress(uint8_t scan);
    };
}