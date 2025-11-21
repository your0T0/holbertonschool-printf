#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing characters and format specifiers
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				count += print_string(str);
			}
			else if (format[i] == '%' )
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);
				count += print_number(num);
			}
                        else if (format[i] == 'b')
                        {
                                 count += print_binary(args);
                        }
                         else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (count);
}
