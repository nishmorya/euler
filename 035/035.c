#include <stdio.h>

int is_prime(int n)
{
	if (n % 2 == 0)
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
	for (int i = 1; i <= 50; i++) {
		printf("%d\n", is_prime(i));
	}

	return 0;
}

