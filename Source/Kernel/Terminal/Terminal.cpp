#include "Terminal.h"

void Clear()
{
    *(char*)0xb8000 = 'Y';
}