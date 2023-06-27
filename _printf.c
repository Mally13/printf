#include "main.h"
#include <stdarg.h>
/**
 * handle_specifier - selects function based on specifier
 * @format: pointer to string format
 * @printf_args: arguments for printf
 * @strLength: Number of already printed characters
 */
void handle_specifier(const char *format, va_list printf_args, int *strLength)
{
	switch (*format)
	{
		case '%':
			_putchar('%');
			(*strLength)++;
			break;
		case 'd':
			handle_int(printf_args, strLength);
			break;
		case 'i':
			handle_base(printf_args, strLength);
			break;
		case 'c':
			handle_char(printf_args, strLength);
			break;
		case 's':
			handle_string(printf_args, strLength);
			break;
		case 'b':
			handle_binaryConv(printf_args, strLength);
			break;
		case 'u':
			handle_unsignedDecimal(printf_args, strLength);
			break;
		case 'o':
			handle_octal(printf_args, strLength);
			break;
		case 'x':
			handle_lowerCaseHex(printf_args, strLength);
			break;
		case 'X':
			handle_upperCaseHex(printf_args, strLength);
			break;
		case 'S':
			handle_special(printf_args, strLength);
			break;
		default:
			break;
	}
}

/**
 * _printf - produces output according to format
 * @format: String Format
 * @...: Additional arguments
 * Return: Return string length
 */
int _printf(const char *format, ...)
{
	int strLength = 0;
	va_list printf_args;

	va_start(printf_args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			handle_specifier(format, printf_args, &strLength);
		}
		else
		{
			_putchar(*format);
			strLength++;
		}
	}
	va_end(printf_args);
	return (strLength);
}
