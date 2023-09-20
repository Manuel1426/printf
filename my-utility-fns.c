#include "main.h"

/**
* is_printable - Evaluates if a char is printable.
*
* @c: Char to be evaluated.
*
* Return: 1 if c is printable, 0 otherwise.
*/
int is_printable(char c)
{
  /**
   * Check if the char is NULL */
    if (c == '\0')
    {
        return (0);
    }

    /**
     * Check if the char is within the range of printable characters */
    if (c >= 32 && c < 127)
    {
        return (1);
    }

    /**
     * Return 0 if the char is not printable */
    return (0);
}

/**
* append_hexa_code - Append ascii in hexadecimal code to buffer.
*
* @buffer: Array of chars.
* @i: Index at which to start appending.
* @ascii_code: ASSCI CODE.
*
* Return: Always 3
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
  /**
   * Check if the buffer pointer is NULL */
    if (buffer == NULL)
    {
        return (-1);
    }

    /**
     * Check if the index is out of bounds */
    if (i < 0 || i >= sizeof(buffer))
    {
        return (-1);
    }

    /**
     * Append the hexadecimal code to the buffer */
    buffer[i++] = '\\';
    buffer[i++] = 'x';
    buffer[i++] = "0123456789ABCDEF"[ascii_code / 16];
    buffer[i++] = "0123456789ABCDEF"[ascii_code % 16];

    /**
     * Return 4, since the hexadecimal code is always 4 characters long */
    return (4);
}

/**
* is_digit - Verifies if a char is a digit.
*
* @c: Char to be evaluated.
*
* Return: 1 if c is a digit, 0 otherwise.
*/
int is_digit(char c)
{
  /**
   * Check if the char is NULL */
    if (c == '\0')
    {
        return (0);
    }

    /**
     * Check if the char is a digit */
    if (c >= '0' && c <= '9')
    {
        return (1);
    }

    /**
     * Return 0 if the char is not a digit */
    return (0);
}

/**
* convert_size_number - Casts a number to the specified size.
*
* @num: Number to be casted.
* @size: Number indicating the type to be casted.
*
* Return: Casted value of num.
*/
long int convert_size_number(long int num, int size)
{
  /**
   * Check if the size is valid */
    if (size != S_LONG && size != S_SHORT)
    {
        return (num);
    }

    /**
     * Cast the number to the specified size */
    if (size == S_LONG)
    {
        return (num);
    }
    else if (size == S_SHORT)
    {
        return ((short)num);
    }

    /**
     * Return the casted value */
    return (num);
}

/**
* convert_size_unsgnd - Casts a number to the specified size.
*
* @num: Number to be casted.
* @size: Number indicating the type to be casted.
*
* Return: Casted value of num.
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
  /**
   * Check if the size is valid */
    if (size != S_LONG && size != S_SHORT)
    {
        return (num);
    }

    /**
     * Cast the number to the specified size */
    if (size == S_LONG)
    {
        return (num);
    }
    else if (size == S_SHORT)
    {
        return ((unsigned short)num);
    }

    /**
     * Return the casted value */
    return (num);
}
