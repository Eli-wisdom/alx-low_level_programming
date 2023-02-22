#include "main.h"

/**
 * print_sign - dislys the sign of a number
 * @n: the int to parameter
 * Return: 1 and prints
 * prints 0 if n is zero
 * prints - if n is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar(48);
		return (0);
	} else if (n < 0)
	{
		_putchar('-');
	}
		return (-1);
}
