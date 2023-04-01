#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - prints a sentence before the main
 * function
 */
void first(void)
{
	printf("Hello , I will always get better\n");
	printf("Long and Greate jorney\n");
}
