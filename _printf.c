#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, the number of characters written.
 *         On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			if (*format == 'c')
				printed_chars += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					printed_chars += _putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
				printed_chars += _putchar('%');
			else
				printed_chars += _putchar('%') + _putchar(*format);
		}
		else
			printed_chars += _putchar(*format);

		format++;
	}

	va_end(args);

	return (printed_chars);
}

