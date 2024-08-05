#pragma once

#include "Types.h"
#include "String.h"
#include "Point.h"

namespace Arkn
{
    class TextRenderer
    {
    private:
        uint8_t m_TextColor;
        uint8_t m_BgColor;

    public:
        uint32_t CurrentYPos;

        TextRenderer() = default;
        TextRenderer(uint8_t forecolour, uint8_t backcolour);

        static void WriteCharacter(uint8_t c, uint8_t forecolour, uint8_t backcolour, Arkn::Point point);
        static void WriteString(const Arkn::String& string, Arkn::Point point, uint8_t t, uint8_t bg);

        /// @brief Writes a line t
        /// @param string The line
        /// @return a rerturn code 0 succeeded -1, means it got to the end of the space height
        static int32_t WriteLine(const Arkn::String& string, uint32_t linePos);

        /// @brief Writes a line t
        /// @param string The line
        /// @return a rerturn code 0 succeeded -1, means it got to the end of the space height
        int32_t WriteLine(const Arkn::String& string);
    };
}