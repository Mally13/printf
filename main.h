#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
/* A header file containing typedefs and function prototypes */


/**
 * format_handler - Typedef for a function pointer
 * to handle different specifiers
 *
 * @printf_args: va_list arguments for the printf_args
 * @strLength: Previously printed characters length
 */
typedef void (*format_handler)(va_list printf_args, int *strLength);

/* function prototypes */
int _putchar(char c);
void handle_int(va_list printf_args, int *strLength);
void handle_base(va_list printf_args, int *strLength);
int _printf(const char *format, ...);
void handle_string(va_list printf_args, int *strLength);
void handle_char(va_list printf_args, int *strLength);
void handle_binaryConv(va_list print_args, int *strLength);
int binaryNumberConv(unsigned int decimalNumber);
void print_octal(int number, int *strLength);
void print_hexadecimal(int number, int *strLength);
void print_decimal(int number, int *strLength);
char *addressConv(unsigned long int num);
void handle_address(va_list printf_args, int *strLength);
void handle_unsignedDecimal(va_list printf_args, int *strLength);
void handle_octal(va_list printf_args, int *strLength);
void handle_lowerCaseHex(va_list printf_args, int *strLength);
void handle_upperCaseHex(va_list printf_args, int *strLength);
int _puts(char *c);

#endif
