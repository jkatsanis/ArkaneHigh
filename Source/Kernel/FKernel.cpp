#include "Terminal/Terminal.h" 

// [org 0x8000]
extern "C" void main(){
    *(char*)0xb8000 = 'Z';
    
    Arkn::Terminal t;
    
    t.FillScreen(0x1f201f201f201f20);
    
    return;
}

