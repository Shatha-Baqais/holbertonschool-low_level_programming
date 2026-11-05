#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long a, b, next;
	unsigned long a_high, a_low, b_high, b_low, high, low;
	unsigned long split = 10000000000UL;

	a = 1;
	b = 2;
	printf("%lu, %lu", a, b);
	for (count = 3; count <= 92; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	a_high = a / split;
	a_low = a % split;
	b_high = b / split;
	b_low = b % split;
	for (count = 93; count <= 98; count++)
	{
		high = a_high + b_high;
		low = a_low + b_low;
		if (low >= split)
		{
			high++;
			low = low - split;
		}
		printf(", %lu%010lu", high, low);
		a_high = b_high;
		a_low = b_low;
		b_high = high;
		b_low = low;
	}
	printf("\n");
	return (0);
}
