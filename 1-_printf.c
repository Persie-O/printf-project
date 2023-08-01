#include <stdio.h>
#include <stdarg.h>

// Custom implementation of printf with basic support for conversion specifiers 'c', 's', and '%'.
// Returns the number of characters printed (excluding the null byte used to end output to strings).
// Writes output to stdout, the standard output stream.
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    // Loop through the format string until we reach the end (null terminator).
    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            char specifier = *format; // Get the conversion specifier

            switch (specifier) {
                case 'c': {
                    // For 'c', get the next argument of type int and print it as a character.
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    // For 's', get the next argument of type char* (string) and print it.
                    char *str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    // For '%', print a single percent sign.
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    // Invalid specifier, ignore it.
                    break;
            }
        } else {
            // If the character is not '%', simply print it.
            putchar(*format);
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args); // Clean up the variable argument list.
    return count; // Return the total number of characters printed.
}
