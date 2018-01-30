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
	}

	int start = values[3];
	int end = values[9] * 7;

	for (int i = start; i <= end; i++) {
		int remainder;
		int number = i;
		while (number > 0) {
			remainder = number % 10;
			number /= 10;
			printf("%d", remainder);
		}
		printf("\n");
	}
	return 0;
}

