#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 **/
int _atoi(char *s)
{
		int x, d, n, len, f, digit;

	x = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (x < len && f == 0)
	{
		if (s[x] == '-')
			++d;

		if (s[x] >= '0' && s[x] <= '9')
		{
			digit = s[x] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[x + 1] < '0' || s[x + 1] > '9')
				break;
			f = 0;
		}
		x++;
	}

	if (f == 0)
		return (0);

	return (n);
}
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 **/
int main(int argc, char *argv[])
{
		int result, n1, n2;

			if (argc < 3 || argc > 3)
					{
								printf("Error\n");
										return (1);
											}

				n1 = _atoi(argv[1]);
					n2 = _atoi(argv[2]);
						result = n1 * n2;

							printf("%d\n", result);

								return (0);
}

