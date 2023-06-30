#include "main.h"
/**
 * handle_S - Prints string and handles non-printable
 * characters
 * @printf_args: va_list arguments for printf
 * @strLength: Number of already printed characters
 */
void handle_S(va_list printf_args, int *strLength)
{
	const char *string;
	unsigned int hexVal, digit, divisor, i;
	char cap;


	string = va_arg(printf_args, char *);
	while (*string)
	{
		
		if (*string == 92)
		{
			_putchar('\\');
			string++;
			(*strLength)++;
			_putchar('x');
			_putchar('\\');
			(*strLength)++;

			hexVal = *string;

			divisor = 1;
			for (i = 1; i < 2; i++)
				divisor *= 16;

			while (divisor > 0)
			{
				digit = hexVal / divisor;
				cap = 'A' + digit;
				_putchar(cap);
				_putchar('\\');
				(*strLength)++;
				hexVal %= divisor;
				divisor /= 16;
			}
		}
		else
		{
			_putchar(*string);
			strLength++;
			string++;
		}
	}
}
