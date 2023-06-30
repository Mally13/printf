#ifndef MAIN_H
#define MAIN_H

#define BINARYBUFF 50

#include <stdio.h>
#include <stdarg.h>
/* A header file containing typedefs and function prototypes */


/**
 * struct FHandler_s - Structure to associate format specifiers
 * with their format handlers functions
 * @specifier: specifier character
 * @format_handler: Pointer to format handler function
 */
typedef struct FHandler_s
{
	char specifier;
	void (*format_handler)(va_list, int *);
} FHandler_t;
/* function prototypes */
int _putchar(char c);
void handle_int(va_list printf_args, int *strLength);
void handle_base(va_list printf_args, int *strLength);
int _printf(const char *format, ...);
void handle_string(va_list printf_args, int *strLength);
void handle_char(va_list printf_args, int *strLength);
void handle_percent(va_list printf_args, int *strLength);
void handle_binaryConv(va_list print_args, int *strLength);
int binaryNumberConv(unsigned int decimalNumber);
void print_octal(int number, int *strLength);
void print_hexadecimal(int number, int *strLength);
void print_decimal(int number, int *strLength);
char *addressConv(unsigned long int num);
void handle_address(va_list printf_args, int *strLength);
void handle_upperCaseHex(va_list printf_args, int *strLength);
void handle_lowerCaseHex(va_list printf_args, int *strLength);
void handle_octal(va_list printf_args, int *strLength);
void handle_unsignedDecimal(va_list printf_args, int *strLength);
int _puts(char *c);
int toAscii(char character);
void printNewHex(int newHex, int *strLength);
void handle_S(va_list printf_args, int *strLength);
char *numberConvert(unsigned long int number, int index, int base);

#endif
