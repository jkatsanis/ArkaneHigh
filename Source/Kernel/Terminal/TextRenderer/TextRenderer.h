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

        void WriteCharacter(uint8_t c, uint8_t forecolour, uint8_t backcolour, Arkn::Point point);
        void WriteString(const Arkn::String& string, Arkn::Point point);

        /// @brief Writes a line t
        /// @param string The line
        /// @return a rerturn code 0 succeeded -1, means it got to the end of the space height
        int32_t WriteLine(const Arkn::String& string);
    };
}