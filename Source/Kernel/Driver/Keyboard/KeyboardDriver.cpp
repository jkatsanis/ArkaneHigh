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

char Arkn::KeyboardDriver::GetKeyCodeAsChar(KeyCode keyCode)
{
    switch (keyCode) {
        case KeyCode::A_RELEASED: return 'A';
        case KeyCode::B_RELEASED: return 'B';
        case KeyCode::C_RELEASED: return 'C';
        case KeyCode::D_RELEASED: return 'D';
        case KeyCode::E_RELEASED: return 'E';
        case KeyCode::F_RELEASED: return 'F';
        case KeyCode::G_RELEASED: return 'G';
        case KeyCode::H_RELEASED: return 'H';
        case KeyCode::I_RELEASED: return 'I';
        case KeyCode::J_RELEASED: return 'J';
        case KeyCode::K_RELEASED: return 'K';
        case KeyCode::L_RELEASED: return 'L';
        case KeyCode::M_RELEASED: return 'M';
        case KeyCode::N_RELEASED: return 'N';
        case KeyCode::O_RELEASED: return 'O';
        case KeyCode::P_RELEASED: return 'P';
        case KeyCode::Q_RELEASED: return 'Q';
        case KeyCode::R_RELEASED: return 'R';
        case KeyCode::S_RELEASED: return 'S';
        case KeyCode::T_RELEASED: return 'T';
        case KeyCode::U_RELEASED: return 'U';
        case KeyCode::V_RELEASED: return 'V';
        case KeyCode::W_RELEASED: return 'W';
        case KeyCode::X_RELEASED: return 'X';
        case KeyCode::Y_RELEASED: return 'Y';
        case KeyCode::Z_RELEASED: return 'Z';
        default: return '*';  // Default case if key code does not match
    }

    return '*';
}

