#include "main.h"

/**
* get_width - Calculates the width for printing
* @format: Formatted string in which to print the arguments.
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: width.
*/
int get_width(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int width = 0;

    /**
     * Check if the format string is NULL */
    if (format == NULL)
    {
        return (width);
    }

    /**
     * Check if the i pointer is NULL */
    if (i == NULL)
    {
        return (width);
    }

    /**
     * Check if the list pointer is NULL */
    if (list == NULL)
    {
        return (width);
    }

    /**
     * Loop through the format string, starting after the first non-whitespace character */
    while (format[curr_i] != '\0')
    {
      /**
       * If the current character is a digit, add it to the width variable */
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
        }
        /**
	 * If the current character is an asterisk, get the width value from the variadic argument list */
        else if (format[curr_i] == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        /**
	 * If the current character is not a digit or an asterisk, break out of the loop */
        else
        {
            break;
        }

        /**
	 * Increment the current index */
        curr_i++;
    }

    /**
     * Update the i pointer to point to the next character after the last width character */
    *i = curr_i - 1;

    /**
    * Return the width variable */
    return (width);
}
