#include "Terminal.h"

void Arkn::Terminal::Stop()
{
    *(char*)0xb8000 = 'L';
}

void Arkn::Terminal::FillScreen(uint64_t color)
{
    uint64_t* videoMem = reinterpret_cast<uint64_t*>(VIDEO_MEMORY);

    for (uint32_t i = 0; i < 500; ++i) {
        videoMem[i] = color;
    }
}