#include "main.h"

/**
 * get_endianness - checks endian
 * 
 * Return: 0 - big, 1 - little
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *ch = (char *) &x;

	return (*ch);
}
