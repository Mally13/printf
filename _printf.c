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
	unsigned long i = 0;
	FHandler_t handlers[] = {
		{'%', handle_percent},
		{'d', handle_int},
		{'i', handle_base},
		{'c', handle_char},
		{'s', handle_string},
		{'b', handle_binaryConv},
		{'u', handle_unsignedDecimal},
		{'o', handle_octal},
		{'p', handle_address},
		{'x', handle_lowerCaseHex},
		{'X', handle_upperCaseHex},
		{'S', handle_S}
	};

	while (i < sizeof(handlers) / sizeof(handlers[0]))
	{
		if (*format == handlers[i].specifier)
		{
			handlers[i].format_handler(printf_args, strLength);
			return;
		}
		i++;
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
