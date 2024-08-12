#pragma once

#include "Types.h"
#include "Macros.h"
#include "Cursor.h"
#include "TextRenderer.h"
#include "IProgram.h"
#include "Screen/Screen.h"


class Terminal : public Arkn::IProgram
{
private:
    Arkn::Cursor m_Cursor;
    Color64 m_TerminalColor;

    void Init(Color64 color);

public:
    Terminal() = default;

    void StartProgram() override;
};
