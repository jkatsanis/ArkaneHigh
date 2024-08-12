#pragma once

#include "Cursor.h"
#include "Terminal/Terminal.h" 
#include "InterruptHandler.h"
#include "KeyboardDriver.h"

namespace Arkn
{
    class ArKernel
    {
    private:
        InterruptHandler m_InterruptHandler;
        KeyboardDriver m_KeyboardDriver;

    public:
        ArKernel() = default;

        void Update ();
    };
}