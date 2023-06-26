#include "main.h"

/**
 * handle_int - handles 'd' format specifier for _printf
 * @printf_args: va_list argument for printf_args
 */

void handle_int(va_list printf_args, int *strLength)
{
	int number, numLength = 0, holder, divisor, digit, i;

	number = va_arg(printf_args, int);
	holder = number;

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
	}

	if (number < 0)
	{
		_putchar('-');
		holder = -holder;
		number = -number;
	}

	while (holder != 0)
	{
		holder /= 10;
		numLength++;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = number / divisor;
		_putchar('0' + digit);
		(*strLength)++;
		number %= divisor;
		divisor /= 10;
	}
}
