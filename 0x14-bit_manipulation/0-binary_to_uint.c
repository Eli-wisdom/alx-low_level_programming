#include "main.h"
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: This string contains the binary digit.
 *
 * Return: the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int val = 0;
	int x;
	

	if (!b){
        return (0);
    }
	for (x = 0; b[x]; x++){
		if (b[x] <'0' || b[x] >'1'){
            return (0);
        }	
		val = 2 *val + (b[x] - '0');
	}
	return (val);
}
