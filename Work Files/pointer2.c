main()
{

	char a[] = "Hello World";
	char *ap = "Goodbye world";

	int i=0;

	while (*ap)
	{
		printf("Addr: %X, %c\n",ap, *ap);
		ap++;
	}

	while (a[i])
	{
		printf("Addr: %X, %c\n",a+i, a[i]);
		i++;
	}

}

