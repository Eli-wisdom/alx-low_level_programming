#include "main.h"
/**
 * reverse_array - revers array of integers
 * @a: array
 * @n: number of elements of array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int x;
	int t;

	for (x = 0; x < n--; x++)
	{
		t = a[x];
		a[i] = a[n];
		a[n] = t;
	}
}

