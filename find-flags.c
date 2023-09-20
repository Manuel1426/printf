#include "main.h"

/**
* get_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int get_flags(const char *format, int *i)
{
int j, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, 
FLAG_SPACE, 0};

/**
* Check if the format string is NULL */
if (format == NULL)
{
return (0);
}

/**
* Check if the i pointer is NULL */
if (i == NULL)
{
return (0);
}

/**
* Loop through the format string, starting after the current i position */
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
/**
* Check if the current character is a flag character */
for (j = 0; FLAGS_CH[j] != '\0'; j++)
{
if (format[curr_i] == FLAGS_CH[j])
{
/**
* Set the corresponding flag in the flags variable */
flags |= FLAGS_ARR[j];
break;
}
}

/**
* If the current character is not a flag character, break out of the loop */
if (FLAGS_CH[j] == '\0')
{
break;
}
}

/**
* Update the i pointer to point to the next character after the last flag character */
*i = curr_i - 1;

/**
* Return the flags variable */
return (flags);
}
