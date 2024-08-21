#pragma once

#include "TextRenderer.h"
#include "Types.h"

#define HASHMAP_SIZE 10

class HashMap {

private:
    int32_t keys[HASHMAP_SIZE];
    bool occupied[HASHMAP_SIZE];
    bool values[HASHMAP_SIZE];
    int32_t EMPTY = -1;             

public:
    HashMap()
    {   
        for(int32_t i = 0; i < HASHMAP_SIZE; i++)
        {
            keys[i] = EMPTY;
            values[i] = EMPTY;
        }           
    }


    void insert(int32_t key, int32_t val)
    {
        int32_t index = (key ^ (key >> 5)) % HASHMAP_SIZE;
  	
        uint8_t IDX = index;


        Arkn::TextRenderer::WriteLine(IDX);

    }


};
