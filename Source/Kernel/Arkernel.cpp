#include "Arkernel.h"

void Arkn::ArKernel::Update()
{
    Terminal t(COLOR_GREEN);
    
    t.FillScreen();

    TextRenderer::WriteLine("Hello");
    TextRenderer::WriteLine("Hello");
    TextRenderer::WriteLine("Hello");
    TextRenderer::WriteLine("Hello");

}
