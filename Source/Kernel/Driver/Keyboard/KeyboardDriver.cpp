#include "KeyboardDriver.h"

void Arkn::KeyboardDriver::HandleKeyboard()
{
    m_KeyReleased = false;
    
    if(Buffer == 0)
    {
        return;
    }

    if(Buffer == 0x84)
    {
        TextRenderer::WriteLine("3 Released");
        m_KeyReleased = true;
    }    

    Buffer = 0;
}

bool Arkn::KeyboardDriver::IsKeyReleased()
{
    return this->m_KeyReleased;
}