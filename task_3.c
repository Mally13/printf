#include "main.h"

/**
 * handle_octal - handles 'o' fomart specifier
 * @printf_args:va_list argument for printf_args
 * @strLength:Number of already printed character in a string
 */
void handle_octal(va_list printf_args, int *strLength)
{
	unsigned int number, numLength = 0, holder, divisor, digit, i;

	number = va_arg(printf_args, int);
	holder = number;

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
	}

	while (holder > 0)
	{
		numLength++;
		holder /= 8;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
	{
		divisor *= 8;
	}
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
 * handle_unsignedInt -
 */
void handle_unsignedDecimal(va_list printf_args, int *strLength)
{
	unsigned int number, numLength = 0, holder, divisor, digit, i;

	number = va_arg(printf_args, unsigned int);
	holder = number;

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
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
 * handle_lowerCaseHex
 */
void handle_lowerCaseHex(va_list printf_args, int *strLength)
{
	unsigned int number, numLength = 0, holder, divisor, digit, i;

	number = va_arg(printf_args, unsigned int);
	holder = number;

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
	}

	while (holder > 0)
	{
		numLength++;
		holder /= 16;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
	{
		divisor *= 16;
	}

	while (divisor > 0)
	{
		digit = number / divisor;
	
		if (digit < 10)
			_putchar('0' + digit);
		else
		{
			_putchar('a' + digit - 10);
		}
		(*strLength)++;
		number %= divisor;
		divisor /= 16;		
	}
}
/**
 *  * handle_lowerCaseHex
 *   */
void handle_upperCaseHex(va_list printf_args, int *strLength)
{
	unsigned int number, numLength = 0, holder, divisor, digit, i;

	number = va_arg(printf_args, unsigned int);
	holder = number;

	if (number == 0)
	{
		_putchar('0');
		(*strLength)++;
		return;
	}

	while (holder > 0)
	{
		numLength++;
		holder /= 16;
	}

	divisor = 1;
	for (i = 1; i < numLength; i++)
	{
		divisor *= 16;
	}

	while (divisor > 0)
	{
		digit = number / divisor;

		if (digit < 10)
			_putchar('0' + digit);
		else
		{
			_putchar('A' + digit - 10);
		}
		(*strLength)++;
		number %= divisor;
		divisor /= 16;
	}
}
