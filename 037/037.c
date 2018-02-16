#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FIRST 11

int is_prime(int n)
{
	if ((n == 0) || (n == 1))
		return 0;
	if ((n == 2) || (n == 3)) {
		return 1;
	} else if (n % 2 == 0) {
		return 0;
	} else if (n % 3 == 0) {
		return 0;
	} else {
		for (int i = 5; i <= n / 2; i+=2) {
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}

int is_truncatable_prime(int n)
{
	int prime_l = n;
	int prime_r = n;
	int digits = log10(n) + 1;
	int d = 0;

	while (d < digits - 1) {
		prime_l %= (int) pow(10, digits - 1 - d);
		prime_r /= 10;
		if (!is_prime(prime_r)) {
			return 0;
		}
		if (!is_prime(prime_l)) {
			return 0;
		}
		d++;
	}
	return 1;
}

int main()
{
	int sum = 0;
	int count = 0;
	int i = FIRST;
	while (count < 11) {
		if (is_prime(i)) {
			if (is_truncatable_prime(i)) {
				count++;
				sum += i;
			}
		}
		i++;
	}

	printf("%d\n", sum);
	return 0;
}

