#include "main.h"

/**
 * print_binary - prints the binary representation  of the number
 * @n: number to be print
 */

void print_binary(unsigned long int n)
{	
	int counter = 0;
	int x;
	unsigned long int val;

	for(x =63; x >=0; x--){
		val =n >> x;
		if (val & 1){
			_putchar('1');
			counter++;
		}
		else if(counter){
			_putchar('0');
		}	
	}
	if(!counter){
		_putchar('0');
	}		
}
