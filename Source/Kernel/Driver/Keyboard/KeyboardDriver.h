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
        uint8_t m_Buffer;

    public:
        KeyboardDriver() = default;

        bool IsKeyReleased();
        void HandleKeyboard();

        void SetBuffer(uint8_t t) { this->m_Buffer = t; }
    };

}