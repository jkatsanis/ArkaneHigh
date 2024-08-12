#pragma once

#include "Types.h"
#include "Macros.h"
#include "Cursor.h"

namespace Arkn
{
    class Screen
    {
    public:
        Screen() = delete;

        static void Fill(Color64 color);
    };
}
