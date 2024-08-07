#include "Arkernel.h"

void Arkn::ArKernel::Update()
{
    Terminal t(COLOR_GREEN);
    
    t.FillScreen();

    TextRenderer::WriteLine("Hello");

    char hex_str[3];  //

    while (1)
    {
        uint8_t keypressed = Arkn::IO::Inb(0x60);
        Arkn::String::Uint8ToHexString(keypressed, hex_str);

        int32_t rtnCode = TextRenderer::WriteLine(Arkn::String(hex_str));
        if(rtnCode == -1)
        {
            t.FillScreen();
        }

    }    
}
