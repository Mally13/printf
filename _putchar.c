#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: On success 1,-1 if error
 */

int _putchar(char c)
{
	(write(1, &c, 1));
	return (1);
}

/**
 * _puts - Puts strings
 * @str: String
 * Return: Str Length
 */
int _puts(char *str)
{
	int counter;

	for (counter = 0; str[counter] != '\0'; counter++)
		_putchar(str[counter]);

	return (counter);
}
