#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    /**
     * Check if the format string is NULL */
    if (format == NULL)
    {
        return (precision);
    }

    /**
     * Check if the i pointer is NULL */
    if (i == NULL)
    {
        return (precision);
    }

    /**
     * Check if the list pointer is NULL */
    if (list == NULL)
    {
        return (precision);
    }

    /**
     * If the current character is not a dot, return the default precision */
    if (format[curr_i] != '.')
    {
        return (precision);
    }

    /**
     * Initialize the precision variable */
    precision = 0;

    /**
     * Loop through the format string, starting after the dot */
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
      /**
      * If the current character is a digit, add it to the precision variable */
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        /**
	 * If the current character is an asterisk, get the precision value from the variadic argument list */
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        /**
	 * If the current character is not a digit or an asterisk, break out of the loop */
        else
        {
            break;
        }
    }

    /**
     * Update the i pointer to point to the next character after the last precision character */
    *i = curr_i - 1;

    /**
     * Return the precision variable */
    return (precision);
}
