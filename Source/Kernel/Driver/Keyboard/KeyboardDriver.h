#pragma once

#include "Types.h"
#include "TextRenderer.h"
#include "Screen/Screen.h"
#include "KeyBoardDriverModels.h"

#define MAX_KEY_CODES 200

namespace Arkn
{
    

    /// @brief 
    /// Scan Code Set 1
    class KeyboardDriver
    {
    private:
        bool m_KeyReleased;

        void Clear();

    public:
        KeyboardDriver() = default;
        
        bool IsKeyReleased();
        bool IsKeyPressed();

        void HandleKeyboard();
        bool IsKeyActive(KeyCode code);

        bool b;
        uint8_t Buffer;

    public:
        static char GetKeyCodeAsChar(KeyCode code);


    };

}
