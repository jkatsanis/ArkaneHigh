#include "Screen.h"

void Arkn::Screen::Fill(Color64 color)
{
    uint64_t* videoMem = reinterpret_cast<uint64_t*>(VIDEO_MEMORY);

    for (uint32_t i = 0; i < 500; ++i) {
        videoMem[i] = color;
    }
}