#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - sum of two diagonals
 * @a: input
 * @size: input
 * Return: Always 0 (Success)
 */
void print_diagsums(int *a, int size)
{
		int n1, n2, x;

			n1 = 0;
				n2 = 0;

					for (x = 0; x < size; x++)
							{
										n1 = n1 + a[x * size + x];
											}

						for (x = size - 1; x >= 0; x--)
								{
											n2 += a[x * size + (size - x - 1)];
												}

							printf("%d, %d\n", n1, n2);
}

