#pragma once

#include "Cursor.h"
#include "Terminal/Terminal.h" 
#include "InterruptHandler.h"

namespace Arkn
{
    class ArKernel
    {
    private:
        InterruptHandler m_InterruptHandler;

    public:
        ArKernel() = default;

        void Update ();
    };
}