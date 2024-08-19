#include "KeyboardDriver.h"

void Arkn::KeyboardDriver::HandleKeyboard()
{    
    if(m_Buffer == 0)
    {
        return;
    }

    if(m_Buffer == 0x84)
    {
        TextRenderer::WriteLine("3 Released");
    }    

    m_Buffer = 0;
}

bool Arkn::KeyboardDriver::IsKeyReleased()
{
    return this->m_KeyReleased;
}