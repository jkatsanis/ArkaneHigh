#pragma once

#include "Types.h"
#include "Macros.h"
#include "Cursor.h"
#include "TextRenderer/TextRenderer.h"

namespace Arkn
{
    class Terminal
    {
    private:
        Cursor m_Cursor;
        Color64 m_TerminalColor;

    public:
        Terminal();
        Terminal(Color64 color);

        void Init();
        void FillScreen();
        void Stop();
    };
}
