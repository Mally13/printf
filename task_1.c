#include "main.h"

/**
 * handle_int - handles 'd' format specifier for _printf
 * @printf_args: va_list argument for printf_args
 * @strLength: number of already printed character in a string
 * automatically.
 * @printf_args: va_list arguments
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
/**
 * print_octal - prints base 8
 */
void print_octal(int number, int *strLength)
{
	unsigned int numLength = 0, holder, divisor, digit, i;

	holder = number;
	while (holder != 0)
	{
		holder /= 8;
		numLength++;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
		divisor *= 8;

	while (divisor > 0)
	{
		digit = number / divisor;
		_putchar('0' + digit);
		(*strLength)++;
		number %= divisor;
		divisor /= 8;
	}
}


/**
 * print_hexadecimal - Prints base 16
 */
void print_hexadecimal(int number, int *strLength)
{
	unsigned int numLength = 0, holder, divisor, digit, i;

	holder = number;
	while (holder != 0)
	{
		holder /= 16;
		numLength++;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
		divisor *= 16;

	while (divisor > 0)
	{
		digit = number / divisor;
		_putchar('0' + digit);
		(*strLength)++;
		number %= divisor;
		divisor /= 16;
	}
}

/**
 * print_decimal - Prints base 10
 */
void print_decimal(int number, int *strLength)
{
	unsigned int numLength = 0, holder, divisor, digit, i;

	holder = number;
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



/**
 * handle_base - handles 'i' specifier, where i in printf should detect base
 * automatically.
 * @printf_args: va_list arguments
 * @strLength: Number of already printed characters
 */
void handle_base(va_list printf_args, int *strLength)
{
	unsigned int number;

	number = va_arg(printf_args, int);

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
	}

	print_decimal(number, strLength);
}
