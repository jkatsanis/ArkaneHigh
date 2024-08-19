#include "Terminal.h"

// Public

void Arkn::Terminal::StartProgram()
{
    Arkn::TextRenderer::WriteLine("Hello from terminal program :)");


    
}

// Private

void Arkn::Terminal::Init(Color64 color)
{
    this->m_TerminalColor = color;
    const uint8_t fgColor = (this->m_TerminalColor >> 60) & 0xFF; // Extracting the first nibble thats the color
    this->m_Cursor.DisableCursor();

    Arkn::TextRenderer::Update(15, fgColor);
}
