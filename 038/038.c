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

int main()
{
	int number[SIZE];
	for (int i = 0; i < SIZE; i++) {
		number[i] = 0;
	}

	for (int i = 1; i < 900; i++) {
		int n = i;
		int digits = log10(n) + 1;
		int j = 0;
		int d = digits;
		while (d)  {
			int divisor = pow(10, d - 1);
			number[j++] = n / divisor;
			n %= divisor;
			d--;
		}
		printf("%d: %d\n", i, is_unique_digit(number, digits));
	}

	return  0;
}

