#include "Arkernel.h"

void Arkn::ArKernel::Update()
{    
    // Creating the systems
    m_InterruptHandler.Init();
    Globals::s_KeyboardDriver_ptr = &m_KeyboardDriver;

    // Driver
    m_KeyboardDriver.Start();


    // Initing programs

    m_TerminalProgram.StartProgram();
       

    while(1)
    {
        // Basicly event based now.. 
        if(Globals::handling)
        {
            // Driver
            m_KeyboardDriver.HandleKeyboard();

            // Programs
            m_TerminalProgram.Update();

            Globals::handling = false;
        }
      
    }
}


