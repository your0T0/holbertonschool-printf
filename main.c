#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    len1 = _printf("Hello %s!\n", "Ghiwooth");
    len2 = printf("Hello %s!\n", "Ghiwooth");

    _printf("len1 = %d\n", len1);
    printf("len2 = %d\n", len2);

    _printf("Character: %c\n", 'A');
    printf("Character: %c\n", 'A');

    _printf("Percent: %%\n");
    printf("Percent: %%\n");

    return (0);
}
