#include "main.h"

/**
* get_size - Calculates the size to cast the argument
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
*
* Return: Precision.
*/
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    /**
     * Check if the format string is NULL */
    if (format == NULL)
    {
        return (size);
    }

    /**
     * Check if the i pointer is NULL */
    if (i == NULL)
    {
        return (size);
    }

    /**
     * If the current character is not a size specifier, return 0 */
    if (format[curr_i] != 'l' && format[curr_i] != 'h')
    {
        return (0);
    }

    /**
     * Set the size variable based on the size specifier */
    if (format[curr_i] == 'l')
    {
        size = S_LONG;
    }
    else if (format[curr_i] == 'h')
    {
        size = S_SHORT;
    }

    /**
     * Update the i pointer to point to the next character after the size specifier */
    *i = curr_i;

    /**
     * Return the size variable */
    return (size);
}
