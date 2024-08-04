#include "String.h"

Arkn::String::String(const char* string)
{
    for(size_t i = 0; string[i] != 0; i++)
    {
        this->m_size = i;
    }
    this->m_size++;
    this->m_str = string;
}

char Arkn::String::operator[](uint32_t idx) const
{
    return this->m_str[idx];
}

// Static functions

void Arkn::String::StringCopy(char dest[], const char src[])
{
    size_t i = 0;
    while (1)
    {
        dest[i] = src[i];
        if (dest[i] == '\0')
        {
            break;
        }
        i++;
    } 
}

void Arkn::String::Uint8ToHexString(uint8_t value, char* buffer)
{
    const char hex_chars[] = "0123456789abcdef";
    
    buffer[0] = hex_chars[(value >> 4) & 0x0F];
    
    buffer[1] = hex_chars[value & 0x0F];
    
    buffer[2] = '\0';
}