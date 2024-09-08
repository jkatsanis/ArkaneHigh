#include "KeyboardDriver.h"

void Arkn::KeyboardDriver::HandleKeyboard()
{
    m_KeyReleased = false;
    
    if(Buffer == 0)
    {
        return;
    }

    if (Buffer & 0x80) 
    {
        m_KeyReleased = true;
    }
    else
    {        
        m_KeyReleased = false; 
    }    
}

bool Arkn::KeyboardDriver::IsKeyActive(KeyCode code)
{
    return code == Buffer;   
}

bool Arkn::KeyboardDriver::IsKeyReleased()
{
    return this->m_KeyReleased;
}

bool Arkn::KeyboardDriver::IsKeyPressed()
{
    return !this->m_KeyReleased;
}

