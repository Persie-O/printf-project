# Printf.
```` c
int _printf(const char *format, ...);
````
This is the first project am working on alone, which consist of replicating the **[printf (3)](https://man7.org/linux/man-pages/man3/printf.3.html)** function of C language, calling it this way **_printf.**

This function is part of the standard library **<stdio>** and to use it we must specify the header file **<stdio.h>**.

Writes the C string pointed by format to the stadard output **<stdout>**. If format includes formart specifiers (subsequences beginning with **%**), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.
### Parameters
| > **format** -> C string that contains the text to be written to stdout.

| Specifier | Output | Example
------------ | ------------ | ----------
| c | Character | A
| s | String of characters |
| % | A% followed by another % character will write a single % to the stream| % i and d | Signed decimal integer | 98
| b | Unsigned binary | 10101
| u | Unsigned decimal integer | 98
| o | Unsigned octal | 5523
| x | Unsigned hexadecimal integer (lowercase) | 36264eb
| X | Unsigned hexadecimal integer (uppercase) | 36264EB
| r | Reversed string | gnirts |
| R | Rot13 string | cevags
##### Return Value.
On **Success**, the **total number** of characters written is returned.
Incase of writing error, the error indicator (ferror) is set and a negative number is returned.

## The Tasks.
-[x] **I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life.**
Write a function that produces output according to a format.

- Prototype: ``int _printf(const char *format, ...);``
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
-format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
-- ``c``
-- ``s``
-- ``%``
|
| -[x] **Education is when you read the fine print. Experience is what you get if you don't**
Handle the following conversion specifiers:
-- ``d``
-- ``i``
## Functions we use.

````c 
int _putchar(char c); /*writes the character c to stdout */
int _printf(const char *format, ...);/* function that produces output according to a format.*/
int print_char(va_list c);/*writes the character c to stdout */
int print_string(va_list s);/*writes the character c to stdout */
int print_int(va_list i);/*function that prints an integer */
int print_dec(va_list d);/* function that prints an decimal*/
````
