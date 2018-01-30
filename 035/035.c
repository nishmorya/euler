#include <stdio.h>

#define LIMIT 100

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
	for (int i = 1; i <= LIMIT; i++) {
		if (is_prime(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}

