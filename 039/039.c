#include <stdio.h>

#define MAX 1000 

int main()
{
	int max_count = 0;
	int max;

	for (int p = 4; p <= MAX; p++) {
		int count = 0;
		int a_max = (p - 1) / 3;
		for (int a = 1; a <= a_max; a++) {
			int a_sqr = a * a;
			int b_max = (p - 3) / 2;
			for (int b = a; b <= b_max; b++) {
				int c = p - (a + b);
				if ((c * c) == a_sqr + (b * b)) {
					count++;
				}
			}
		}

		if (max_count < count) {
			max_count = count;
			max = p;
		}
	}

	printf("%d\n", max);
	return 0;
}

