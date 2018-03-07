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

int *separate_digits(int n, int digits, int start_index, int *number)
{
	int d = digits;
	int k = start_index;

	while (d) {
		int divisor = pow(10, d - 1);
		number[k++] = n / divisor;
		n %= divisor;
		d--;
	}
	return number;
}

int *construct_number(int integer, int *number)
{
	int i = 1;
	int temp_prod = integer * i;
	int digits = log10(temp_prod) + 1;
	int tot_digits = digits;
	int exit_digits = tot_digits;
	int start_index = 0;
	i++;

	while (tot_digits <= SIZE) {
		separate_digits(temp_prod, digits, start_index, number);
		start_index += (digits - 1);
		temp_prod = integer * i;
		digits = log10(temp_prod) + 1;
		exit_digits = tot_digits;
		tot_digits += digits;
		start_index++;
		i++;
	}

	int diff = SIZE - exit_digits;
	if (diff) {
		temp_prod = 0;
		separate_digits(temp_prod, 1, start_index, number);
	}

	return number;
}

int convert_to_number(int *number)
{
	int value = 0;
	for (int i = 0; i < SIZE; i++) {
		value += number[i] * pow(10, SIZE - i - 1);
	}
	return value;
}

int is_non_zero(int *number)
{
	for (int i = 0; i < SIZE; i++) {
		if (number[i] == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int *number = (int*)malloc(sizeof(int) * SIZE);
	int i = 1;
	int digits = log10(i) + 1;
	int largest = i;

	while (digits < 5) {
		construct_number(i, number);
		int value = convert_to_number(number);
		if ((is_unique_digit(number, SIZE)) && (is_non_zero(number)) && (largest < value)) {
			largest = value;
		}
		i++;
		digits = log10(i) + 1;
	}

	free(number);
	printf("%d\n", largest);

	return 0;
}

