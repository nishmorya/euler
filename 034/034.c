#include <stdio.h>

int factorial(int n)
{
	int fac = 0;
	if (n == 1) {
		return 1;
	} else {
		fac += n * factorial(n - 1);
	}
	return fac;
}

int main()
{
	printf("%d\n", factorial(3));
	return 0;
}

