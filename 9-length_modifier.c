#include <stdio.h>

// Custom printf function with support for flag characters '+', ' ', and '#'
// and length modifiers 'l' and 'h' for conversion specifiers 'd', 'i', 'u', 'o', 'x', 'X'
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format); // Start variable argument list processing

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'

            // Handle flag characters
            int flag_plus = 0;
            int flag_space = 0;
            int flag_hash = 0;

            // Check for flag characters
            while (*format == '+' || *format == ' ' || *format == '#') {
                switch (*format) {
                    case '+':
                        flag_plus = 1;
                        break;
                    case ' ':
                        flag_space = 1;
                        break;
                    case '#':
                        flag_hash = 1;
                        break;
                }
                format++;
            }

            // Handle length modifiers
            int length_modifier_h = 0;
            int length_modifier_l = 0;

            while (*format == 'h' || *format == 'l') {
                if (*format == 'h') {
                    length_modifier_h++;
                } else if (*format == 'l') {
                    length_modifier_l++;
                }
                format++;
            }

            // Handle conversion specifier
            char conversion_specifier = *format;
            if (conversion_specifier == 'd' || conversion_specifier == 'i') {
                // Handle integer format
                long long num;

                if (length_modifier_h == 1) {
                    num = va_arg(args, int); // Treat as 'short int'
                } else if (length_modifier_h == 2) {
                    num = va_arg(args, int); // Treat as 'signed char'
                } else if (length_modifier_l == 1) {
                    num = va_arg(args, long int);
                } else if (length_modifier_l == 2) {
                    num = va_arg(args, long long int);
                } else {
                    num = va_arg(args, int);
                }

                if (flag_plus && num >= 0) {
                    putchar('+');
                } else if (flag_space && num >= 0) {
                    putchar(' ');
                }
                printf("%lld", num);
            } else if (conversion_specifier == 'u' || conversion_specifier == 'o' ||
                       conversion_specifier == 'x' || conversion_specifier == 'X') {
                // Handle unsigned integer, octal, hexadecimal format
                unsigned long long num;

                if (length_modifier_h == 1) {
                    num = va_arg(args, unsigned int); // Treat as 'unsigned short int'
                } else if (length_modifier_h == 2) {
                    num = va_arg(args, unsigned int); // Treat as 'unsigned char'
                } else if (length_modifier_l == 1) {
                    num = va_arg(args, unsigned long int);
                } else if (length_modifier_l == 2) {
                    num = va_arg(args, unsigned long long int);
                } else {
                    num = va_arg(args, unsigned int);
                }

                if (flag_hash && num != 0) {
                    if (conversion_specifier == 'o') {
                        putchar('0');
                    } else if (conversion_specifier == 'x' || conversion_specifier == 'X') {
                        putchar('0');
                        putchar(conversion_specifier);
                    }
                }

                if (conversion_specifier == 'u') {
                    printf("%llu", num);
                } else if (conversion_specifier == 'o') {
                    printf("%o", num);
                } else if (conversion_specifier == 'x') {
                    printf("%x", num);
                } else if (conversion_specifier == 'X') {
                    printf("%X", num);
                }
            } else {
                // If the specifier is not handled, print the '%' as-is
                putchar('%');
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
    short int shInt = 123;
    unsigned char uchar = 'A';
    long long int llInt = 9223372036854775807LL;
    unsigned long ulong = 4294967295UL;

    // Example usage of custom_printf with length modifiers
    custom_printf("Short int: %hd, Unsigned char: %hhu\n", shInt, uchar);
    custom_printf("Long long int: %lld, Unsigned long: %lu\n", llInt, ulong);

    return 0;
}
