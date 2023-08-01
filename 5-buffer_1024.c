#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> // For write system call

#define BUFFER_SIZE 1024

// Custom implementation of printf with support for 'u', 'o', 'x', 'X' conversion specifiers.
// Returns the number of characters printed (excluding the null byte used to end output to strings).
// Writes output to stdout, the standard output stream.
int _printf(const char *format, ...);

// Helper function to print an unsigned integer in binary format
void print_binary(unsigned int num);

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    // Buffer to store the output before calling write
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    // Loop through the format string until we reach the end (null terminator).
    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            char specifier = *format; // Get the conversion specifier

            switch (specifier) {
                // (Previous cases remain the same)
		// if you wish to use the previous case take a referrence from file 4

                default:
                    // Invalid specifier, ignore it.
                    break;
            }
        } else {
            // If the character is not '%', store it in the buffer.
            buffer[buffer_index++] = *format;
            count++;
        }

        // If the buffer is full or we reach the end of the format string, write the buffer to stdout.
        if (buffer_index >= BUFFER_SIZE || *(format + 1) == '\0') {
            write(1, buffer, buffer_index);
            buffer_index = 0; // Reset buffer index for the next iteration
        }

        format++; // Move to the next character in the format string
    }

    va_end(args); // Clean up the variable argument list.
    return count; // Return the total number of characters printed.
}

// (print_binary and other helper functions remain the same)

