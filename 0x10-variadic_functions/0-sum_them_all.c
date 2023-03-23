i#include "variadic_functions.h"
#include <stdarg.h>


	/**
	 * sum_them_all - Returns the sum of all the paramters.
	 * @n: The number of paramters passed to the function.
	 * @...: A variable number of paramters to calculate the sum of.
	 *
	 * Return: If n == 0 - 0.
	 *         Otherwise - the sum of all parameters.
	 */
	int sum_them_all(const unsigned int n, ...)
		{
			int result = 0;
    va_list args;
    va_start(args, n);
    
    for (int i = 0; i < n; i++) {
        result += va_arg(args, int);
    }
	        
	    va_end(args);
	    return result;
		}


