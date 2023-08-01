#include <stdio.h>

// Custom printf function with support for flag characters: '+', ' ', and '#'
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

            // Handle conversion specifier
            char conversion_specifier = *format;
            if (conversion_specifier == 'd' || conversion_specifier == 'i') {
                // Handle integer format
                int num = va_arg(args, int);
                if (flag_plus && num >= 0) {
                    putchar('+');
                } else if (flag_space && num >= 0) {
                    putchar(' ');
                }
                printf("%d", num);
            } else if (conversion_specifier == 'x') {
                // Handle hexadecimal format
                unsigned int num = va_arg(args, unsigned int);
                if (flag_hash) {
                    putchar('0');
                    putchar('x');
                }
                printf("%x", num);
            } else if (conversion_specifier == 'f') {
                // Handle floating-point format
                double num = va_arg(args, double);
                if (flag_plus && num >= 0) {
                    putchar('+');
                } else if (flag_space && num >= 0) {
                    putchar(' ');
                }
                printf("%f", num);
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
    int num = 42;
    double floatNum = 3.14;
    unsigned int hexNum = 0xABCD;

    // Example usage of custom_printf with flag characters
    custom_printf("Integer with plus flag: %+d, Integer with space flag: % d\n", num, num);
    custom_printf("Floating-point with plus flag: %+f, Floating-point with space flag: % f\n", floatNum, floatNum);
    custom_printf("Hexadecimal with hash flag: %#x\n", hexNum);

    return 0;
}
