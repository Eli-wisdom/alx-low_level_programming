#include "main.h"
#include <stdio.h>
/**
 * clear_bit - set  at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change
 * Return: 1 , -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;
	unsigned int hold;

	if (index > 64)
		return (-1);
	hold = index;
	for (x = 1; hold > 0; x *= 2, hold--)
		;

	if ((*n >> index) & 1)
		*n -= x;

	return (1);
}
