#include "main.h"
/**
* handle_binaryConv - Converts integers to binary
* @printf_args: Varargs Usage
* @strLength: String Length
*/
void handle_binaryConv(va_list printf_args, int *strLength)
{
	int decimalNumber, numLength = 0, divisor, i, digit, holder, binaryNumber;

	decimalNumber = va_arg(printf_args,unsigned int);
	binaryNumber = binaryNumberConv(decimalNumber);
	holder = binaryNumber;

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
		digit = binaryNumber / divisor;
		_putchar('0' + digit);
		(*strLength)++;
		binaryNumber %= divisor;
		divisor /= 10;
	}

}

/**
* binaryNumberConv - Binary conversion
* @decimalNumber: Parameter
* Return: The binsry number
*/

int binaryNumberConv(unsigned int decimalNumber)
{
	int binaryNum;

	if (decimalNumber == 0)
		binaryNum = 0;
	else
		binaryNum = decimalNumber % 2 + 10 * (binaryNumberConv(decimalNumber / 2));
	return (binaryNum);
}
