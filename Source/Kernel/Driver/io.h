#pragma once

#include "Types.h"

// Read a byte from the specified I/O port
uint8_t inb(uint16_t port);

// Write a byte to the specified I/O port
void outb(uint16_t port, uint8_t value);

// Wait for I/O operations to complete
void io_wait();
