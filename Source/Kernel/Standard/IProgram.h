#pragma once

#include "TextRenderer.h"

namespace Arkn
{
    class IProgram
    {
    public:
        virtual void StartProgram() { Arkn::TextRenderer::WriteLine("Starting a empty program.."); };
        virtual void Update() { Arkn::TextRenderer::WriteLine("Updateing a empty program.."); };
    };
}