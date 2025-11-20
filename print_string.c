#include "main.h"

/**
 * print_string - prints a string to stdout
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}

	return (count);
}
