#include "main.h"
/**
* handle_print - Prints an argument based on its type.
*
* @fmt: Formatted string in which to print the arguments.
* @list: List of arguments to be printed.
* @ind: Index of the next character in the format string.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags.
* @width: Minimum width of the output.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: Number of characters printed, or -1 on error.
*/
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
    int i, unknow_len = 0;

    /**
     * Check if the format string is NULL. */
    if (fmt == NULL)
    {
        return (-1);
    }

    /**
     * Check if the i pointer is NULL. */
    if (ind == NULL)
    {
        return (-1);
    }

    /**
     * Check if the list pointer is NULL. */
    if (list == NULL)
    {
        return (-1);
    }

    /**
     * Check if the buffer pointer is NULL. */
    if (buffer == NULL)
    {
        return (-1);
    }

    /**
     * Loop through the array of format types. */
    for (i = 0; fmt_types[i].fmt != '\0'; i++)
    {
      /**
       * If the current format type matches the current character in the format string, call the corresponding print function. */
        if (fmt[*ind] == fmt_types[i].fmt)
        {
            return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
        }
    }

    /**
     * If the current character in the format string does not match any of the format types, print it as a literal character. */
    if (fmt_types[i].fmt == '\0')
    {
      /**
       * If the current character is a null terminator, return -1 to indicate that the end of the format string has been reached. */
        if (fmt[*ind] == '\0')
        {
            return (-1);
        }

        /**
	 * Print the current character to the console. */
        unknow_len += write(1, &fmt[*ind], 1);

        /**
	 * If the previous character in the format string was a space, print another space to the console. */
        if (fmt[*ind - 1] == ' ')
        {
            unknow_len += write(1, " ", 1);
        }
        /**
	 * Otherwise, if the width specifier is greater than zero, decrement the index pointer and continue looping. */
        else if (width)
        {
            (*ind)--;
            while (fmt[*ind] != ' ' && fmt[*ind] != '%')
            {
                (*ind)--;
            }
            if (fmt[*ind] == ' ')
            {
                (*ind)--;
            }
            return (1);
        }
    }

    /**
     * Return the number of characters printed. */
    return (unknow_len);
}
