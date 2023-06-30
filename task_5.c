#include "main.h"
/**
 * toHex - converts a sting to hex value
 * @character: char to be converted
 * Return: Hex value of capital char
 */
int toHex(char character)
{
	int hexValue;

	hexValue = character - 'A' + 10;
	return (hexValue);
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
	int i, j, newHex, digit, divisor, numLength = 0, holder;


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
			newHex = toHex(string[i]);
			holder = newHex;
			while (holder > 0)
			{
				holder /= 16;
				numLength++;
			}
			divisor = 1;
			for (j = 0; j < numLength; j++)
				divisor *= 16;
			while (divisor > 0)
			{
				digit = newHex / divisor;
				_putchar('0' + digit);
				(*strLength)++;
				newHex %= divisor;
				divisor /= 16;
			}
		}
		else
		{
			_putchar(string[i]);
			(*strLength)++;
		}
	}
}
