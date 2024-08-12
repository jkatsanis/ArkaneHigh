#include "Arkernel.h"

void Arkn::ArKernel::Update()
{
    Terminal t(COLOR_GREEN);
    
    t.FillScreen();

    TextRenderer::WriteLine("Hello");

    // char hex_str[3];  // cd Dev/ArkaneHigh/Source
    init_idt();

    while(1){ }
}
