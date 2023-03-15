#include <stdio.h>
		
#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * main - Display the minimum number of coins to
		
 * make change for an amount of money
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: 0 (Success)
		
 */
		
int main(int argc, char *argv[])
		
{
		
	int n, x, result;
		
	int coins[] = {25, 10, 5, 2, 1};
		

		
	if (argc != 2)
		
	{
		
		printf("Error\n");
		
		return (1);
		
	}
		

		
	num = atoi(argv[1]);
		
	result = 0;
		

		
	if (n < 0)
		
	{
		
		printf("0\n");
		
		return (0);
		
	}
		

		
	for (x = 0; x < 5 && n >= 0; x++)
		
	{
		
		while (n >= coins[x])
		
		{
		
			result++;

			n -= coins[x];
		}	
	}
	printf("%d\n", result);
		
	return (0);		
}
