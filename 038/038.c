#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 9

int is_unique_digit(int number[], int digits)
{
	for (int i = 0; i < digits - 1; i++) {
		for (int j = i + 1; j < digits; j++) {
			if (number[i] == number[j])
					return 0;
		}
	}
	return 1;
}

int *separate_digits(int n, int digits, int *number)
{
	int d = digits;
	int k = 0;

	while (d) {
		int divisor = pow(10, d - 1);
		number[k++] = n / divisor;
		n %= divisor;
		d--;
	}
	return number;
}

int main()
{
	for (int i = 1; i < 900; i++) {
		int digits = log10(i) + 1;
		int *number = (int*)malloc(sizeof(int) * digits);
		separate_digits(i, digits, number);
		printf("%d\n", is_unique_digit(number, digits));
		free(number);

		/*while (digits < SIZE + 1) {
			int n = i * j;
			number = digitize(n, digits);
			if (is_unique_digit(i, digits) == 0) {
				return 0;
			} else {

			}
			j++;
		}*/

	}
}

