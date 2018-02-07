#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000000

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
	int ***number;
	number = (int***)malloc(sizeof(int**) * (LIMIT / 2));
	int count = 0;
	int remainder;

	for (int i = 3; i <= LIMIT; i = i + 2) {
		if (is_prime(i)) {
			int flag = 0;
			int prime = i;
			int digits = log10(i) + 1;
			number[count] = (int**)malloc(sizeof(int*) * digits);
			number[count][0] = (int*)malloc(sizeof(int) * digits);
			int index = 0;

			while (prime) {
				remainder = prime % 10;
				if (remainder % 2 == 0) {
					flag = 1;
					break;
				}
				number[count][0][index++] = remainder;
				int l = index;
				int r = 1;

				while (l < digits) {
					number[count][r] = (int*)malloc(sizeof(int) * digits);
					number[count][r++][l++] = remainder;
				}

				l = 0;
				if (r < digits) {
					number[count][r++][l++] = remainder;
				}

				prime /= 10;
			}

			if (flag)
				continue;

			int rotation = 0;
			while (rotation < digits) {
				int location = 0;
				int value = 0;
				while (location < digits) {
					value = value + (number[count][rotation][location] * pow(10, location));
					location++;
				}
				rotation++;
				if (!is_prime(value)) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				count++;
			}
		}
	}

	printf("%d\n", count + 1);
	return 0;
}

