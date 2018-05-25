#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 9
#define MAX 987654321

int is_prime(int n)
{
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;
	if (!(n % 6 == 1) && (!(n % 6 == 5)))
		return 0;
	int s = sqrt(n);
	for (int i = 5; i <= s; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int is_n_digit_pandigital(int n)
{
	int digits = 0;
	int *number = malloc(sizeof(int) * LENGTH);

	if (n == 0) {
		return 0;
	}

	while (n) {
		int remainder =	n % (LENGTH + 1);
		if (remainder == 0)
			return 0;
		else {
			for (int i = 0; i < digits; i++) {
				if (number[i] == remainder) {
					free(number);
					return 0;
				}
			}
			number[digits++] = remainder;
		}
		n /= LENGTH + 1;
	}

	int d = digits;
	while (d > 0) {
		if (number[d - 1] > digits) {
			free(number);
			return 0;
		}
		d--;
	}
	free(number);

	return 1;
}

int main()
{
	for (int i = MAX; i >= 1; i--) {
		if (is_n_digit_pandigital(i)) {
			if (is_prime(i)) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}

