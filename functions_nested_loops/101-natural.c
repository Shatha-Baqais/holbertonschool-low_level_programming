#include <stdio.h>

/**
 * main - prints the sum of all multiples of 3 or 5 below 1024
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (i < 1024)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
