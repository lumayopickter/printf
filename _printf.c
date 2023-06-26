#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char ch;
	char *str;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					write(1, &ch, 1);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						write(1, str, 1);
						str++;
						printed_chars++;
					}
					break;
				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return printed_chars;
}

