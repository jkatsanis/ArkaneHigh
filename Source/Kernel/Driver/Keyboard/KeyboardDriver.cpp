#include "KeyboardDriver.h"

void Arkn::KeyboardDriver::Start()
{
    KeyboardDriver::B_PRESSED = KeyCodeData(KeyCode::B_PRESSED, 0);
    Arkn::TextRenderer::WriteLine(KeyboardDriver::B_PRESSED.KeyCodeArrayPos); 
}

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

void Arkn::KeyboardDriver::Clear()
{
    this->m_KeyReleased = false;
    for(int i = 0; i < MAX_KEY_CODES; i++)
    {
        m_KeyCodes[i] = false;
    }
}

Arkn::KeyCodeData Arkn::KeyboardDriver::B_PRESSED = KeyCodeData();

