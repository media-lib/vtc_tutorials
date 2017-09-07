#include <stdio.h>

int main (int argc, char *argv[])
{

	int i = 0;

	do {
		i = getchar();
		    getchar();

		if ( i == 'X' )
			continue;

		printf("ASCII %d.\n", i);

	} while( i != 'Q');

}
