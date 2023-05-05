#include "main.h"

/**
 * get_endianness -  endianness
 * Return: 0 endian, or 1 endian
 */
int get_endianness(void)
{
	int num;

	num = 1;
	if (*(char *)&num == 1)
		return (1);
	else
		return (0);
}
