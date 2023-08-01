#include <stdio.h>

// Helper function to print non-printable characters in the required format
void print_non_printable(char ch) {
    printf("\\x%02X", (unsigned char)ch); // Print the ASCII code value in hexadecimal (always 2 characters)
}

// Custom printf function with support for the 'S' specifier
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format); // Start variable argument list processing

    char ch;
    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'

            if (*format == 'S') {
                char *str = va_arg(args, char *); // Get the string argument

                // Loop through the characters of the string
                while (*str) {
                    ch = *str;
                    if (ch >= 32 && ch < 127) {
                        putchar(ch); // Printable character, print as-is
                    } else {
                        print_non_printable(ch); // Non-printable character, print in custom format
                    }
                    str++;
                }
            } else {
                putchar('%'); // If the specifier is not 'S', print the '%' as-is
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
    // Example usage of custom_printf with the 'S' specifier
    char str[] = "Hello,\nWorld!\x07"; // Contains a newline, exclamation mark, and a BEL character (ASCII 7)

    printf("Original string: %s\n", str);

    printf("Formatted string: ");
    custom_printf("%S", str);
    printf("\n");

    return 0;
}

