#include <stdio.h>

int main (int argc, char *argv[])
{

	char Buffer[10];

	if (argc < 2)				/* Something on the cmd line? */
	{
		printf("Usage: We need an option.\n");
		exit(1);
	}	

	strncpy(Buffer,argv[1],9);		/* Move it to Buffer */

	switch (Buffer[1])			/* Skip over the '/' */
	{
		case '?':
		  printf("They want help.\n");
		break;
		
		case 'A':
		case 'a':
		  printf("Option A\n");
		break;

		case 'B':
		case 'b':
		  printf("Option B\n");
		break;

		default:
		  printf("Unknown Option\n");
	} /* End of Switch */

}