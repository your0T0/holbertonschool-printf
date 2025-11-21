Custom _printf Project
======================

This team project recreates a simplified version of the C library function printf.
It focuses on variadic functions, format parsing, and modular programming.

Team Members:
- Mariam Backroush
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

_____________________________________________________________________________________
                                 Task number 0 - Printf
________________________________________________________________________________________

The goal of this task is to build the basic structure of our own printf function.
In this stage, the function only needs to handle the three simple specifiers:
c , s , %

Prototype used:
int _printf(const char *format, ...);

What _printf should do in Task 0:
- Read the format string character by character.
- Print any normal character directly to the output.
- When a % appears, check the next character to decide what to print.
- Handle the following:
  %c  prints a single character
  %s  prints a string
  %%  prints a percent sign

Files created in this task:

1) _printf.c
   - This file contains the main logic of our custom printf.
   - It loops through the format string.
   - It checks for % and chooses the correct action.
   - It uses helper functions to print characters or strings.

2) main.h
   - Header file for all prototypes.
   - Required so all C files know the functions we created.
   - Includes:
     int _printf(const char *format, ...);
     int print_char(int c);
     int print_string(char *str);

3) print_string.c
   - Contains the function that prints a full string.
   - Loops through characters and prints them using write.
   - Returns how many characters were printed.

4) functions.c
   - Contains helper functions such as:
     print_char for printing a single character.
   - More helper functions will be added in the next tasks.

At the end of Task 0:
- Our _printf is able to mimic the basic behavior of the real printf,
  but only for c , s , and %.
- No flags, no width, no precision, no numbers yet.
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
___________________________________________________________________________
                                 Task number 2 - man page
___________________________________________________________________________

In this task we do not change the C code of _printf.
Instead, we create a manual page file to document our function.

Required file name:
man_3_printf

What is this file:
- It is a Unix manual (man) page for our _printf function.
- It can be read using the command:
  man ./man_3_printf

What the man page explains:
- NAME:
  Short description of _printf as a custom implementation of printf.

- SYNOPSIS:
  Shows the prototype and header:
  #include "main.h"
  int _printf(const char *format, ...);

- DESCRIPTION:
  Explains how _printf works:
  - It prints characters to the standard output.
  - It uses a format string with conversion specifiers.
  - It describes all supported specifiers:
    %c, %s, %%, %d, %i

- RETURN VALUE:
  - On success: returns the number of printed characters
    (excluding the terminating null byte).
  - On error: returns -1.

- LIMITATIONS:
  - This version does not handle flags, field width,
    precision or length modifiers.
  - It does not reproduce the full buffer management
    of the standard printf.

- AUTHORS:
  - Names of the team members who wrote the function and the man page.

- SEE ALSO:
  - Reference to the original printf manual: printf(3)

The purpose of Task 2 is to document our _printf function in the same style
as real C library functions, so that any user or reviewer can understand
how to call it and what behavior to expect without reading the source code.
