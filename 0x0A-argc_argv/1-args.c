#include <stdio.h>
#include "main.h"
/**
 * main - Display the number of arguments passed
 * @argc: number of arguments
 * @argv: array of arguments
 * return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
(void) argv;
printf("%d\n", argc - 1);
return (0);
}
