#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIGITS 9
#define SIZE 5

int *unique_insert(int prod, int *products, int *used_size, int *tot_size)
{
	int flag = 0;

	for (int i = 0; i <= *used_size - 1; i++) {
		if (prod == products[i]) {
			flag = 1;
		}
	}

	if (!flag) {
		if (*used_size >= *tot_size) {
			products = (int*)realloc(products, sizeof(int) * SIZE);
		}
		products[(*used_size)++] = prod;
	}

	return products;
}

int is_unique_digit_number(int number, int length)
{
	int digits[length];
	int flag = 0;
	int i = 0;
	int remainder = number % 10;

	if (remainder) {
		digits[i++] = remainder;
		number /= 10;
		while (number) {
			digits[i] = number % 10;

			if (!digits[i]) {
				flag = 1;
				break;
			}

			for (int j = 0; j < i; j++) {
				if (digits[i] == digits[j]) {
					flag = 1;
					break;
				}
			}

			if (flag)
				break;

			number /= 10;
			i++;
		}
		return !flag;
	}
	return 0;
}

int *products_pandigital(int multiplicand_s, int multiplicand_l, int multiplier_s, int multiplier_l, int *products, int *used_size, int *tot_size)
{
	int multiplicand_e = pow(10, multiplicand_l);
	int multiplier_e = pow(10, multiplier_l);
	int total_l = multiplicand_l + multiplier_l;
	int total_e = pow(10, total_l);
	int max_prod = pow(10, DIGITS - total_l);

	for (int i = multiplicand_s; i < multiplicand_e; i++) {
		if (is_unique_digit_number(i, multiplicand_l)) {
			for (int j = multiplier_s; j < multiplier_e; j++) {
				if (is_unique_digit_number(j, multiplier_l)) {
					int concat_operands = (i * multiplier_e) + j;
					if (is_unique_digit_number(concat_operands, total_l)) {
						int prod = i * j;
						if ((prod < max_prod) && (is_unique_digit_number(prod, DIGITS - total_l))) {
							if (is_unique_digit_number(((prod * total_e) + concat_operands), DIGITS))
								unique_insert(prod, products, used_size, tot_size);
						}
					}
				}
			}
		}
	}
	
	return products;
}

int main()
{
	int *products = (int*)malloc(sizeof(int) * SIZE);
	int used_size = 0;
	int tot_size = SIZE;
	int sum = 0;

	products = products_pandigital(1, 1, 1000, 4, products, &used_size, &tot_size);
	products = products_pandigital(10, 2, 100, 3, products, &used_size, &tot_size);

	for (int i = 0; i < used_size; i++) {
		sum += products[i];
	}

	printf("%d\n", sum);
	return 0;
}

