#include "main.h"
/**
* handle_char - Prints Characters to output
* @printf_args: Varargs usage
* @strLength: String Length
*/
void handle_char(va_list printf_args, int *strLength)
{
	int character;

	character = va_arg(printf_args, int);
	if (character != NULL)
	{
		_putchar(character);
		(*strLength)++;
	}
}

/**
* handle_string - Prints string to stdout
* @printf_args: Varargs usage
* @strLength: String Length
*/
void handle_string(va_list printf_args, int *strLength)
{
	char *string;

	string = va_arg(printf_args, char *);
	if (!string)
		string = "(null)";

	_puts(string);
	(*strLength)++;
}
