#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: On success, returns the number of characters written.
 * On error, returns -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
			{
				count += _putchar('%');
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);
				count += _putchar(ch);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return count;
}

