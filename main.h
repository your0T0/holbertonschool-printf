#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
int print_string(va_list args);
int print_number(va_list args);
int print_char(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase)
int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str); 
int print_number(int n);
int print_binary(va_list args);
#endif
