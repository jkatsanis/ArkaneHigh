#pragma once

#include "Types.h"
#include "Macros.h"

namespace Arkn
{
    class Terminal
    {
    public:
        void FillScreen(uint64_t color);
        void Stop();
    };
}
