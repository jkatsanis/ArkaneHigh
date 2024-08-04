#include "Terminal.h"

void Terminal::Clear()
{
    *(char*)0xb8000 = 'K';
}

void Terminal::Stop()
{
    *(char*)0xb8000 = 'L';
}