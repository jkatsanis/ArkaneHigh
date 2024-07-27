char sauger[] = "SAUGER";

// kernel.cpp
extern "C" void kernel_main() {
    // Example: simple message to the screen (assuming a VGA text mode setup)
    const char* message = "Hello from C++ Kernel!";
    char* video_memory = (char*)0xb8000;  // VGA text mode base address

    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07;  // Light gray on black background
    }

    while (1) {}  // Infinite loop to prevent returning
}
