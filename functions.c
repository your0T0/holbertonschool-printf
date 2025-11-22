#include "main.h"

/**
* _putchar -writes a character to stdout
* @c: character to print
* Return: 1 on success
*/
int _putchar(char c)
{
 return (write(1, &c, 1));
}
/**
* print_string - prints a string
* @str: string to print
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
/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
    unsigned int num;
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');

    return (count);
}

int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int mask = 1 << 31;
    int started = 0;
    int count = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (mask > 0)
    {
        if (n & mask)
        {
            write(1, "1", 1);
            count++;
            started = 1;
        }
        else if (started)
        {
            write(1, "0", 1);
            count++;
        }
        mask >>= 1;
    }

    return (count);
}

int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0, count = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i--)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}

int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[22];
    int i = 0, count = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}

int print_hex(va_list args, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[22];
    int i = 0, count = 0;
    char *hex;

    if (uppercase)
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = hex[n % 16];
        n /= 16;
    }

    while (i--)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}
