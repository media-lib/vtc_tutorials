main()
{

	char a[] = "Hello World";
	char *ap = a;

	int i=0;

	while (*ap)
	{
		printf("Addr: %X, %c\n",ap, *ap);
		ap++;
	}


	for ( ap = a, i=0 ; i < 20; i++)
	{
		*(ap+i) = '\0';
	}
}

