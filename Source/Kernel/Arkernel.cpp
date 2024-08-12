#include "Arkernel.h"

void Arkn::ArKernel::Update()
{
    Terminal t(COLOR_GREEN);
    
    t.FillScreen();

    TextRenderer::WriteLine("Hello");

    // char hex_str[3];  // cd Dev/ArkaneHigh/Source
    m_InterruptHandler.Init();
    
    nKeyboardDriver_ptr = &m_KeyboardDriver;

    while(1){ }
}
