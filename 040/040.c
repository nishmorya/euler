#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define SIZE 6

int main()
{
	int prod = 1;
	int count = 1;
	int number = 1;
	int *reverse = malloc(sizeof(int) * SIZE);
	int *fraction = malloc(sizeof(int) * SIZE);
	int flag = 0;

	while (number <= MAX) {
		int n = number;
		int i = 0;
		while (n > 0) {
			reverse[i++] = n % 10;
			n = n / 10;
		}

		int k = i - 1;
		for (int j = 0; j < i; j++) {
			fraction[j] = reverse[k--];
			if ((count == 1) || (count == 10) || (count == 100) || (count == 1000) || (count == 10000) || (count == 100000) || (count == 1000000)) {
				prod *= fraction[j];
				if (count == 1000000) {
					flag = 1;
					break;
				}
			}
			count++;
		}
		if (flag)
			break;
		number++;
	}

	printf("%d", prod);
	return 0;
}

