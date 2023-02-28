#include "main.h"
/**
 * puts2 - print one character
 * and a new line
 * @str: input
 * Return: print
 **/
void puts2(char *str)
{
int longit = 0;
int t = 0;
char *y = str;
int o;

while (*y != '\0')
{
y++;
longit++;
}
t = longit - 1;
for (o = 0 ; o <= t ; o++)
{
if (o % 2 == 0)
{
_putchar(str[o]);
}
}
_putchar('\n');
}
