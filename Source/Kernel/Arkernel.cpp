#include "Arkernel.h"

void Arkn::ArKernel::Update()
{    
    // Creating the systems
    m_InterruptHandler.Init();
    nKeyboardDriver_ptr = &m_KeyboardDriver;


    // Initing programs

    m_TerminalProgram.StartProgram();

    while(1){ }
}
