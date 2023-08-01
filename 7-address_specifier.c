#include <stdio.h>

// Custom printf function with support for the 'p' specifier
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format); // Start variable argument list processing

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'

            if (*format == 'p') {
                void *ptr = va_arg(args, void *); // Get the pointer argument

                // Print the pointer address in hexadecimal format
                printf("%p", ptr);
            } else {
                putchar('%'); // If the specifier is not 'p', print the '%' as-is
                putchar(*format);
            }
        } else {
            putchar(*format); // Print regular characters
        }

        format++; // Move to the next character in the format string
    }

    va_end(args); // End variable argument list processing
}

int main() {
    int x = 42;
    char ch = 'A';
    float f = 3.14f;
    void *ptr = &x;

    // Example usage of custom_printf with the 'p' specifier
    custom_printf("Integer: %p, Character: %p, Float: %p, Pointer: %p\n", &x, &ch, &f, ptr);

    return 0;
}
