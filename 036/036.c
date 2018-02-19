#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 1000000

int is_palindromic(int n)
{
	int digits = log10(n) + 1;
	int *number;
	number = (int*) malloc(sizeof(int) * digits);
	int i = 0;

	while (n) {
		number[i++] = n % 10;
		n /= 10;
	}

	int mid;

	if (digits % 2) {
		mid = (digits - 2) / 2;
	} else {
		mid = (digits - 1) / 2;
	}

	int flag = 0;
	int j = 0;
	int k = digits - 1;
	while (j <= mid) {
		if (number[j++] != number[k--]) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		return 0;
	}

	return 1;
}

int main()
{
	return 0;
}

