#pragma once

#include "Types.h"
#include "Macros.h"
#include "Cursor.h"
#include "TextRenderer.h"
#include "Screen/Screen.h"
#include "Globals.h"
#include "IProgram.h"

namespace Arkn 
{
    class Terminal : public IProgram
    {
    private:
        Cursor m_Cursor;
        Color64 m_TerminalColor;

        void Init(Color64 color);
        void OnKeyBoardPress(uint8_t scan);

    public:
        Terminal() = default;

        void StartProgram() override;
        void Update() override;
    };

}