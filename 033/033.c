#include <stdio.h>

#define START 10
#define END 99

int main()
{
	for (int i = START; i < END; i++) {
		for (int j = i + 1; j < END; j++) {
			printf("%d %d\n", i, j);
		}
	}

	return 0;
}

