#include "main.h"
/**
 * _strchr - locate character in a string
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 **/
char *_strchr(char *s, char c)
{
		int n = 0;

			for (; s[n] >= '\0'; n++)
					{
								if (s[n] == c)
												return (&s[n]);
									}
				return (0);
}

