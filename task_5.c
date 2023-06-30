#include "main.h"
/**
 * toAscii - converts a char to ascii value
 * @character: char to be converted
 * Return: Hex value of capital char
 */
int toAscii(char character)
{
	int asciiValue;

	asciiValue = (int) character;
	return (asciiValue);
}
/**
 * printNewHex - prints Hex
 * @newHex: value to be printed
 * @strLength: value of printed characters
 */
void printNewHex(int newHex, int *strLength)
{
	int j, digit, divisor, numLength = 0, holder;

	holder = newHex;
	while (holder > 0)
	{
		holder /= 16;
		numLength++;
	}
	if (numLength == 1)
	{
		_putchar('0');
		(*strLength)++;
	}
	divisor = 1;
	for (j = 1; j < numLength; j++)
		divisor *= 16;
	while (divisor > 0)
	{
		digit = newHex / divisor;
		if (digit < 10)
		{
			_putchar('0' + digit);
			(*strLength)++;
		}
		else
		{
			_putchar('A' + digit - 10);
			(*strLength)++;
		}
		newHex %= divisor;
		divisor /= 16;
	}
}
/**
 * handle_S - Prints string and handles non-printable
 * characters
 * @printf_args: va_list arguments for printf
 * @strLength: Number of already printed characters
 */
void handle_S(va_list printf_args, int *strLength)
{
	char *string;
	int i, newHex;

	string = va_arg(printf_args, char *);
	if (!string)
		return;
	for (i = 0; string[i]; i++)
	{
		if (((string[i]) > 0 && (string[i]) < 32) || (string[i]) >= 127)
		{
			_putchar('\\');
			_putchar('x');
			(*strLength) += 2;
			newHex = toAscii(string[i]);
			printNewHex(newHex, strLength);
		}
		else
		{
			_putchar(string[i]);
			(*strLength)++;
		}
	}
}
