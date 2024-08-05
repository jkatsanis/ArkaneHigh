#include "TextRenderer.h"

Arkn::TextRenderer::TextRenderer(uint8_t fg, uint8_t bg)
    : m_TextColor(fg), m_BgColor(bg)
{
    
}

// Static public functions
void Arkn::TextRenderer::WriteCharacter(uint8_t c, uint8_t forecolour, uint8_t backcolour, Arkn::Point point)
{
    uint16_t attrib = (backcolour << 4) | (forecolour & 0x0F);
    volatile uint16_t * where;
    where = (volatile uint16_t *)0xB8000 + (point.y * 80 + point.x) ;
    *where = c | (attrib << 8);
}

void Arkn::TextRenderer::WriteString(const Arkn::String& string, Arkn::Point point, uint8_t t, uint8_t bg)
{
    for(size_t i = 0; i < string.GetSize(); i++)
    {
        Arkn::TextRenderer::WriteCharacter(string[i], t, bg, point);
        point.x += 1;
    }
}

int32_t Arkn::TextRenderer::WriteLine(const Arkn::String& string, uint32_t pos)
{
    const Arkn::Point point(0, pos);

    Arkn::TextRenderer::WriteString(string, point, 15, 0);

    pos++;

    return (pos == 100) ? -1 : 0;
}

int32_t Arkn::TextRenderer::WriteLine(const Arkn::String& line)
{
    const Arkn::Point point(0, CurrentYPos);

    Arkn::TextRenderer::WriteString(line, point, m_TextColor, m_BgColor);

    if(CurrentYPos == 100)
    {
        CurrentYPos = 0;
        return -1;
    }
    CurrentYPos++;
    return 0;
}
