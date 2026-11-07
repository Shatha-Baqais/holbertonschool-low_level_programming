#include <stdio.h>

/**
 * main - prints the numbers from 1 to 100 with Fizz, Buzz and FizzBuzz
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i > 1)
			printf(" ");
		if (i % 15 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);
		i++;
	}
	printf("\n");
	return (0);
}
