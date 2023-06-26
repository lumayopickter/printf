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
 * _puts - Writes a string to stdout.
 * @str: The string to be written.
 *
 * Return: The number of characters written.
 */
int _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_number - Prints a number to stdout.
 * @n: The number to be printed.
 *
 * Return: The number of digits printed.
 */
int print_number(int n)
{
	int digits = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
		digits++;
	}

	if (n / 10)
		digits += print_number(n / 10);

	_putchar((n % 10) + '0');
	digits++;

	return (digits);
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
				printed_chars += _puts(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_number(va_arg(args, int));
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

