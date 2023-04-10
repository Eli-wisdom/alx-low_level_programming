#include "main.h"

/**
 * get_bit - Returns the value of a bit at an index
 * @n:The search
 * @index: The bit
 * Return: The value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int val;

	if (index > 63){
		return (-1);
	}
	val = (n >> index) & 1;
	return (val);
}
