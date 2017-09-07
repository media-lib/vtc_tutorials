func1();
func2();
func3();

extern int v1, v2, v3;

int vm = 0;

main() {
	printf("main, vm=%d, v1=%d, v2=%d, v3=%d\n", vm, v1, v2, v3);

	v1++;
	func1();

	v2++;
	func2();

	v3++;
	func3();
}

