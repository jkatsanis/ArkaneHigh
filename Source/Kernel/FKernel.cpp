#include "Terminal/Terminal.h" 

// [org 0x8000]
extern "C" void main(){
    *(char*)0xb8000 = 'Z';
    
    Terminal t;
    t.Clear();
    t.Stop();
    
    return;
}

