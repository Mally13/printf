#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to format
 * @format: String Format
 * @...: Additional arguments
 * Return: Return string length
 */
int _printf(const char *format, ...)
{
	int character, counter = 0, strLength = 0;
	const char *string;
	va_list printf_args;

	va_start(printf_args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
					_putchar('%');
					strLength++;
					break;
				case 'd':
					handle_int(printf_args, &strLength);
					break;
				case 'i':
					handle_base(printf_args, &strLength);
					break;
				default:
					break;
			}
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