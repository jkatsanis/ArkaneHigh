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

Arkn::String::String(char value)
{
    static char buffer[2]; // Static array to hold the char and the null terminator
    buffer[0] = value;         // Set the first element to the char
    buffer[1] = '\0';      // Set the second element to the null terminator
    this->m_str = buffer;
    this->m_size = 1;
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

const char* Arkn::String::IntToString(int32_t value)
{
    static char buffer[12];  // Fixed-size buffer for the integer string
    char* ptr = buffer + sizeof(buffer) - 1;  // Point to the end of the buffer
    int is_negative = 0;

    *ptr = '\0';  // Null-terminate the string

    if (value < 0) {
        is_negative = 1;
        value = -value;  // Make the value positive for processing
    }

    do {
        *(--ptr) = (value % 10) + '0';  
        value /= 10;  
    } while (value > 0);

    if (is_negative) {
        *(--ptr) = '-';  
    }

    return ptr; 
}