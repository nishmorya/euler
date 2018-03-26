#include <stdio.h>

#define LIMIT 354294 /* 9 ^ 5 * 6 */

int pow_five(int d)
{
	int square = d * d;
	return square * square * d;
}

int main()
{
	int n = 32;
	int digits[7];
	int sum_numbers = 0;

	while (n < LIMIT) {
		int remainder = n;
		int length = 0;

		while (remainder > 0) {
			digits[length++] = remainder % 10;
			remainder /=  10;
		}

		int sum_powers = 0;

		for (int i = 0; i < length; i++) {
			sum_powers += pow_five(digits[i]);
		}

		if (n == sum_powers) {
			sum_numbers += sum_powers;
		}

		n++;
	}

	printf("%d\n", sum_numbers);
	return 0;
}

