#pragma once

#include "Cursor.h"
#include "Terminal/Terminal.h" 
#include "idt.h"

namespace Arkn
{
    class ArKernel
    {
    public:
        ArKernel() = default;

        void Update ();
    };
}