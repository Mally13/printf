#include "main.h"
/**
* handle_binaryConv - Converts integers to binary
* @printf_args: Varargs Usage
* @strLength: String Length
*/
void handle_binaryConv(va_list printf_args, int *strLength)
{
	int decimalNumber;
	char *binaryStr;

	decimalNumber = va_arg(printf_args, int);
	binaryStr = numberConvert(decimalNumber, 2, 0);

	_puts(binaryStr);
	(*strLength)++;
}
/**
* numberConvert - Binary conversion
* @number: Parameter
* @index: second parameter
* @base: Base index
* Return: The binsry number
*/

char *numberConvert(unsigned long int number, int index, int base)
{
	static char *rep;
	static char buffer[BINARYBUFF];
	char *numberHolder;

	rep = (base)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	numberHolder = &buffer[49];
	*numberHolder = '\0';
	do {
		*--numberHolder = rep[number % index];
		number /= index;
	} while (number != 0);

	return (numberHolder);
}
