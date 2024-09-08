#pragma once

#include "Types.h"
#include "TextRenderer.h"
#include "Screen/Screen.h"

#define MAX_KEY_CODES 200

namespace Arkn
{
    enum KeyCode
    {
        NOTHING = 0,
        
        A_PRESSED = 0x1E,
        B_PRESSED = 0x30,
        C_PRESSED = 0x2E,
        D_PRESSED = 0x20,
        E_PRESSED = 0x12,
        F_PRESSED = 0x21,
        G_PRESSED = 0x22,
        H_PRESSED = 0x23,
        I_PRESSED = 0x17,
        J_PRESSED = 0x24,
        K_PRESSED = 0x25,
        L_PRESSED = 0x26,
        M_PRESSED = 0x32,
        N_PRESSED = 0x31,
        O_PRESSED = 0x18,
        P_PRESSED = 0x19,
        Q_PRESSED = 0x10,
        R_PRESSED = 0x13,
        S_PRESSED = 0x1F,
        T_PRESSED = 0x14,
        U_PRESSED = 0x16,
        V_PRESSED = 0x2F,
        W_PRESSED = 0x11,
        X_PRESSED = 0x2D,
        Y_PRESSED = 0x15,
        Z_PRESSED = 0x2C,
            
        // Released
        A_RELEASED = A_PRESSED + 0x80,
        B_RELEASED = B_PRESSED + 0x80,
        C_RELEASED = C_PRESSED + 0x80,
        D_RELEASED = D_PRESSED + 0x80,
        E_RELEASED = E_PRESSED + 0x80,
        F_RELEASED = F_PRESSED + 0x80,
        G_RELEASED = G_PRESSED + 0x80,
        H_RELEASED = H_PRESSED + 0x80,
        I_RELEASED = I_PRESSED + 0x80,
        J_RELEASED = J_PRESSED + 0x80,
        K_RELEASED = K_PRESSED + 0x80,
        L_RELEASED = L_PRESSED + 0x80,
        M_RELEASED = M_PRESSED + 0x80,
        N_RELEASED = N_PRESSED + 0x80,
        O_RELEASED = O_PRESSED + 0x80,
        P_RELEASED = P_PRESSED + 0x80,
        Q_RELEASED = Q_PRESSED + 0x80,
        R_RELEASED = R_PRESSED + 0x80,
        S_RELEASED = S_PRESSED + 0x80,
        T_RELEASED = T_PRESSED + 0x80,
        U_RELEASED = U_PRESSED + 0x80,
        V_RELEASED = V_PRESSED + 0x80,
        W_RELEASED = W_PRESSED + 0x80,
        X_RELEASED = X_PRESSED + 0x80,
        Y_RELEASED = Y_PRESSED + 0x80,
        Z_RELEASED = Z_PRESSED + 0x80
    };


    class KeyCodeData
    {
    private:
        KeyCode m_KeyCode;

    public:
        uint8_t KeyCodeArrayPos;

        KeyCodeData() = default;
        KeyCodeData(KeyCode code, uint8_t pos)
        {
            this->m_KeyCode = code;
            this->KeyCodeArrayPos = pos;
        }
    };


    /// @brief 
    /// Scan Code Set 1
    class KeyboardDriver
    {
    private:
        bool m_KeyReleased;

        void Clear();

    public:
        KeyboardDriver() = default;
        
        bool IsKeyReleased();
        bool IsKeyPressed();

        void HandleKeyboard();
        bool IsKeyActive(KeyCode code);

        bool b;
        uint8_t Buffer;

    };

}
