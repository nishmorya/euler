#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	int fac = 0;
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return 1;
	} else {
		fac += n * factorial(n - 1);
	}
	return fac;
}

int main()
{
	int *values;
	values = malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		values[i] = factorial(i);
		printf("%d\n", values[i]);
	}

	return 0;
}

