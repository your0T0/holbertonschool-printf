Custom _printf Project
======================

This team project recreates a simplified version of the C library function printf.
It focuses on variadic functions, format parsing, and modular programming.

Team Members:
- Mariam Almaleki
- Yara Aldossari

General Rules:
- All files must end with a new line
- A README.md file is mandatory
- No more than 5 functions per file
- No global variables allowed
- Must include main.h with all prototypes

Also there are limited functions to use:
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

_________________________________________________________________________________
                                 Task number 0 - Printf
_________________________________________________________________________________
We need to build a function following the rules mentioned above. this function should
be able to print all these specifers (c s %).
using Prototype: int _printf(const char *format, ...);
printing (c) which is a single character
printing (s) which is a string
printing (%) which is a percentage sign
creating 4 files:
_printf.c - For Script
main.h - Header files and  prototypes
print_string.c - Prints a string
functions.c - 
_________________________________________________________________________________
                                 Task number 1 - printf
_________________________________________________________________________________
In this task we extend our _printf function to handle integer numbers.

We still use the same prototype:
int _printf(const char *format, ...);

Now the function must also print:
- %d : print a signed decimal integer (negative or positive)
- %i : same as %d, print a signed integer

To do that, we added and modified the following:

1) New helper function:
   - print_number(int n)
     This function:
     - checks if the number is negative, prints '-' and converts it to positive
     - uses recursion to print each digit from left to right
     - returns how many characters were printed

2) main.h:
   - add the prototype:
     int print_number(int n);

3) _printf.c:
   - inside the big if/else block for format specifiers, we added:
     else if (format[i] == 'd' || format[i] == 'i')
         - take the next argument as int using va_arg
         - call print_number and add its return value to the total count

After Task 1, our _printf can handle:
- %c : character
- %s : string
- %% : percent sign
- %d : signed integer
- %i : signed integer
