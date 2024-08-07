#include "Terminal.h"

Arkn::Terminal::Terminal(Color64 color)
    : m_TerminalColor(color)
{ 
    this->Init();
}

Arkn::Terminal::Terminal()
{
    this->m_TerminalColor = COLOR_BLUE;
    this->Init();
}

void Arkn::Terminal::Init()
{
    const uint8_t fgColor = (this->m_TerminalColor >> 60) & 0xFF; // Extracting the first nibble thats the color
    this->m_Cursor.DisableCursor();

    Arkn::TextRenderer::Update(15, fgColor);
}

void Arkn::Terminal::Stop()
{
    *(char*)0xb8000 = 'L';
}

void Arkn::Terminal::FillScreen()
{
    uint64_t* videoMem = reinterpret_cast<uint64_t*>(VIDEO_MEMORY);

    for (uint32_t i = 0; i < 500; ++i) {
        videoMem[i] = this->m_TerminalColor;
    }
}