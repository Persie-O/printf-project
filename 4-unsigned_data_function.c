#include <stdio.h>
#include <stdarg.h>

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
                case 'b': {
                    // For 'b', get the next argument of type unsigned int and print it in binary.
                    unsigned int num = va_arg(args, unsigned int);
                    print_binary(num);
                    count++;
                    break;
                }
                case 'u': {
                    // For 'u', get the next argument of type unsigned int and print it as an unsigned integer.
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%u", num);
                    count++;
                    break;
                }
                case 'o': {
                    // For 'o', get the next argument of type unsigned int and print it as an octal number.
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%o", num);
                    count++;
                    break;
                }
                case 'x': {
                    // For 'x', get the next argument of type unsigned int and print it as a lowercase hexadecimal number.
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%x", num);
                    count++;
                    break;
                }
                case 'X': {
                    // For 'X', get the next argument of type unsigned int and print it as an uppercase hexadecimal number.
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%X", num);
                    count++;
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

// Helper function to print an unsigned integer in binary format
void print_binary(unsigned int num) {
    int binary[32];
    int i = 0;

    // Convert the integer to binary representation
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    // Print the binary representation in reverse order
    for (int j = i - 1; j >= 0; j--) {
        putchar('0' + binary[j]);
    }
}
