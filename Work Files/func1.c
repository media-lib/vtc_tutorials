extern int vm, v2, v3;
int v1 = 1;

func1(){
	static int fv1;

	return printf("f1, vm=%d, v1=%d, v2=%d, v3=%d\n", vm, v1, v2, v3);
}

