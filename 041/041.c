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

int is_pandigital(int n)
{
	int *number = malloc(sizeof(int) * LENGTH);
	int i = 0;

	if (n == 0)
		return 0;

	while (n) {
		int remainder =	n % (LENGTH + 1);
		if (remainder == 0)
			return 0;
		else {
			for (int j = 0; j < i; j++) {
				if (number[j] == remainder)
					return 0;
			}
			number[i++] = remainder;
		}

		n /= LENGTH + 1;
	}
	return 1;
}

int main()
{
	/*for (int i = MAX; i > 475391826; i--) {
		if ((is_pandigital(i)) && (is_prime(i))) {
			printf("%d\n", i);
			break;
		}
	}*/

	for (int i = 475391826; i > 1; i--) {
		if ((is_pandigital(i)) && (is_prime(i))) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}

