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
	int total = 0;
	int *factorials;
	factorials = malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		factorials[i] = factorial(i);
	}

	int start = factorials[3];
	int end = factorials[9] * 7;

	for (int i = start; i <= end; i++) {
		int number = i;
		int sum = 0;

		while (number) {
			sum += factorials[number % 10];
			number /= 10;
		}

		if (sum == i)
			 total += sum;
	}

	printf("%d\n", total);
	return 0;
}

