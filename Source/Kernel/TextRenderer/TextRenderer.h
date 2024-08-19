#pragma once

#include "Types.h"
#include "String.h"
#include "Point.h"

namespace Arkn
{
    class TextRenderer
    {
    private:
        static uint8_t m_TextColor;
        static uint8_t m_BgColor;

    public:
        static uint32_t CurrentYPos;

        TextRenderer() = delete;

        static void Update(uint8_t txt, uint8_t bg);
        static void WriteCharacter(uint8_t c, uint8_t forecolour, uint8_t backcolour, Arkn::Point point);
        static void WriteString(const Arkn::String& string, Arkn::Point point, uint8_t t, uint8_t bg);

        /// @brief Writes a line t
        /// @param string The line
        /// @return a rerturn code 0 succeeded -1, means it got to the end of the space height
        static int32_t WriteLine(const Arkn::String& string);
        static int32_t WriteLine(uint8_t i);

    };
}