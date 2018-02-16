#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000000
#define SIZE 6

int is_prime(int n)
{
	if ((n == 2) || (n == 3))
		return 1;
	else if (n % 2 == 0)
		return 0;
	else if (n % 3 == 0)
		return 0;
	else {
		for (int i = 5; i <= n / 2; i = i + 2) {
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}

int main()
{
	int number[SIZE][SIZE];
	int remainder;
	int count = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			number[i][j] = 0;
		}
	}

	for (int i = 3; i <= LIMIT; i+=2) {
		if (is_prime(i)) {
			int flag = 0;
			int prime = i;
			int digits = log10(i) + 1;
			int index = 0;
			int l, r;

			while (prime) {
				remainder = prime % 10;
				if (remainder % 2 == 0) {
					flag = 1;
					break;
				}
				number[0][index++] = remainder;

				l = index;
				r = 1;

				while (l < digits) {
					number[r++][l++] = remainder;
				}

				l = 0;

				while (r < digits) {
					number[r++][l++] = remainder;
				}
				prime /= 10;
			}

			if (flag) {
				continue;
			}

			r = 0;

			while (r < digits) {
				l = 0;
				int value = 0;

				while (l < digits) {
					value = value + (number[r][l] * pow(10, l));
					l++;
				}

				if (!is_prime(value)) {
					flag = 1;
					break;
				}

				r++;
			}

			if (flag == 0) {
				count++;
			}
		}
	}

	printf("%d\n", count + 1);
	return 0;
}

