#include "main.h"

/**
 * flip_bits - Counts the number of flips
 * to get from one number to another
 * @n: Number
 * @m: Number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x;
	int counter = 0;
	unsigned long int val = n ^ m;
	unsigned long int curr;
	

	for (x =63; x >=0; x--)
	{
		curr = val >> x;
		if (curr & 1){
			counter++;
		}	
	}
	return (counter);
}
