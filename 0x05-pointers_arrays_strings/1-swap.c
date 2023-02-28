#include "main.h"
/**
 ** swap_int -: swaps the values of two integers
 * @a: integer_1
 * @b: integer_2
 **/
void swap_int(int *a, int *b)
{
		int m;

			m = *a;
				*a = *b;
					*b = m;
}
