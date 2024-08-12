#include "io.h"

// Read a byte from the specified I/O port
uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ volatile ("inb %1, %0" : "=a" (value) : "d" (port));
    return value;
}

// Write a byte to the specified I/O port
void outb(uint16_t port, uint8_t value) {
    __asm__ volatile ("outb %0, %1" : : "a" (value), "d" (port));
}

// Wait for I/O operations to complete
void io_wait() {
    __asm__ volatile ("outb %%al, $0x80" : : "a" (0));
}
