#include "main.h"

/**
 * _islower - check if char is lowercase
 * @c: is the arguement to be checked
 * Return: 1 or  otherwise 0.
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
