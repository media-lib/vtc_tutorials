#include <stdio.h>

main()
{
	int c;

	while (( c=getchar() ) != EOF)
		putchar(tolower(c));

	fprintf(stderr,"Job Ended.\n");

	return 0;
}