#pragma once

#include "Types.h"
#include "TextRenderer.h"
#include "Screen/Screen.h"

#define MAX_KEY_CODES 200

namespace Arkn
{
    enum KeyCode
    {
        NOTHING = 0,
        A_PRESSED = 0x1C,
        A_RELEASED = 0xF01C,  // Combined using a single integer
        B_PRESSED = 0x30,
    };

    class KeyCodeData
    {
    private:
        KeyCode m_KeyCode;

    public:
        uint8_t KeyCodeArrayPos;

        KeyCodeData() = default;
        KeyCodeData(KeyCode code, uint8_t pos)
        {
            this->m_KeyCode = code;
            this->KeyCodeArrayPos = pos;
        }
    };


    class KeyboardDriver
    {
    private:
        bool m_KeyPressed;
        bool m_KeyReleased;
        bool m_KeyCodes[MAX_KEY_CODES];

        void Clear();

    public:
        KeyboardDriver() = default;

        void Start();
        bool IsKeyReleased();
        void HandleKeyboard();


        uint8_t Buffer;

    public:
        static KeyCodeData B_PRESSED;

    };

}
