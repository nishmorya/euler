#include <stdio.h>

#define START 10
#define END 99

int main()
{
	for (int i = START; i < END; i++) {
		float nu_d1 = i / 10;
		float nu_d2 = i % 10;
		float riverse_nu = nu_d2 * 10 + nu_d1;
		for (int j = i + 1; j < END; j++) {
			float de_d1 = j / 10;
			float de_d2 = j % 10;
			float value1 = (nu_d1 * 10 + nu_d2) / (de_d1 * 10 + de_d2);
			if (riverse_nu == j)
				continue;
			printf("%d %d ", i, j);
			printf("%f\n", value1);
		}
	}

	return 0;
}

