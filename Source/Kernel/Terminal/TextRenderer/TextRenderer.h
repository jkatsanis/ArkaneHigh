#pragma once

#include "Types.h"
#include "String.h"
#include "Point.h"

namespace Arkn
{
    class TextRenderer
    {
    private:
        uint32_t m_CurrentYPos;
        uint8_t m_TextColor;
        uint8_t m_BgColor;

    public:
        TextRenderer() = default;
        TextRenderer(uint8_t forecolour, uint8_t backcolour);

        void WriteCharacter(uint8_t c, uint8_t forecolour, uint8_t backcolour, Arkn::Point point);
        void WriteString(const Arkn::String& string, Arkn::Point point);
        void WriteLine(const Arkn::String& string);
    };
}