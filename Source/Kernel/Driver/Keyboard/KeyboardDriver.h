#pragma once

#include "Types.h"
#include "TextRenderer.h"
#include "Screen/Screen.h"

namespace Arkn
{
    class KeyboardDriver
    {
    private:
        bool m_KeyReleased;

    public:
        KeyboardDriver() = default;

        bool IsKeyReleased();
        void HandleKeyboard();

                uint8_t Buffer;

    };

}