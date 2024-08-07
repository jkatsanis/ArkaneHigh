#include "Arkernel.h"

// [org 0x8000]

int x = 2;

extern "C" void main(){    

    if(x== 2)
    {
        Arkn::ArKernel kernel;
        kernel.Update();
    }
    

        
    return;
}

