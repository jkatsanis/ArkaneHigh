#include "Arkernel.h"

void Arkn::ArKernel::Update()
{
    Terminal t(COLOR_GREEN);
    
    t.FillScreen();

    t.TRenderer.WriteLine("Hello");
    t.TRenderer.WriteString("Hello", Arkn::Point(5, 5));

    while (1)
    {
       //  uint8_t keypressed = Arkn::IO::Inb(0x60);
       //  Arkn::TextRenderer::WriteLine(keypressed);
    }    
}
