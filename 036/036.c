#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000000

int is_palindromic(int n, int base, int digits)
{
	if (n % base == 0)
		return 0;

	int *number = (int*)malloc(sizeof(int) * digits);
	int i = 0;

	while (n) {
		number[i++] = n % base;
		n /= base;
	}

	int j = 0;
	int k = digits - 1;

	while (j < k) {
		if (number[j++] != number[k--]) {
			free(number);
			return 0;
		}
	}

	free(number);
	return 1;
}

int main()
{
	int sum = 0;

	for (int i = 1; i < LIMIT; i++) {
		int digits = log10(i) + 1; 
		if (is_palindromic(i, 10, digits)) {
			digits = log2(i) + 1;
			if (is_palindromic(i, 2, digits)) {
				sum += i;
			}
		}
	}

	printf("%d\n", sum);
	return 0;
}

