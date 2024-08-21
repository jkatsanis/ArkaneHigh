#pragma once

#include "Globals.h"
#include "Cursor.h"
#include "InterruptHandler.h"
#include "KeyboardDriver.h"
#include "Terminal.h"
#include "Hashmap.h"

namespace Arkn
{
    class ArKernel
    {
    private:
        InterruptHandler m_InterruptHandler;
        KeyboardDriver m_KeyboardDriver;

        Terminal m_TerminalProgram;

    public:
        ArKernel() = default;

        void Update();
    };
}