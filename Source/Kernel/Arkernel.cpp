#include "Arkernel.h"

void Arkn::ArKernel::Update()
{    
    // Creating the systems
    m_InterruptHandler.Init();
    Globals::s_KeyboardDriver_ptr = &m_KeyboardDriver;


    // Initing programs

    m_TerminalProgram.StartProgram();
  
 
        

    while(1)
    { 
        if(!Globals::handling)
        {
            // Driver
            m_KeyboardDriver.HandleKeyboard();

            // Programs
            m_TerminalProgram.Update();


            for (volatile int i = 0; i < 1000; i++) {
            // Do nothing, just burn CPU cycles
            }
        }
    }
}


