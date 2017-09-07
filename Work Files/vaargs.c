#include <stdarg.h>
#include <stdio.h>

double average ( int num, ... )
{
    double sum = 0;
    int x = 0;

    va_list arguments;				/* Macro to create the arg list */
    		
    va_start( arguments, num );			/* Find the first argument */
         
    
    for ( x = 0; x < num; x++ )        
    {
        sum += va_arg ( arguments, double );	/* Get each argument */
    }

    va_end( arguments );			/* Clean up the list */

    return sum / num;                      
}

main()
{
    printf( "%f\n", average ( 4, 3.6, 2.0, 5.2, 4.6 ) );
    printf( "%f\n", average ( 3, 2.5, 4.8, 6.2 ) );
}
