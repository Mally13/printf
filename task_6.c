#include "main.h"
/**
* handle_address - Prints address of a variable
* @printf_args: Varargs Variables
* @strlength: String length
*/
void handle_address(va_list printf_args, int *strlength)
{
	unsigned long int address;
	char *strAddress;

	address = va_arg(printf_args, unsigned long int);
	if (!address)
	{
	_puts("(nil)");
	strlength += 3;
	}

	strAddress = addressConv(address);
	strlength += _puts("0x");
	strlength += _puts(strAddress);

}

/**
* addressConv - Converts int to hex string
* @num: Hex int to be converted
* Return: Hex string
*/
char *addressConv(unsigned long int num)
{
	static char *hexChar = "0123456789abcdef";
	char *strAddress;
	static char hexHolder[50];

	strAddress = &hexHolder[49];
	*strAddress = '\0';

	do {
		*--strAddress = hexChar[num % 16];
		num /= 16;
	} while (num != 0);

	return (strAddress);
}
