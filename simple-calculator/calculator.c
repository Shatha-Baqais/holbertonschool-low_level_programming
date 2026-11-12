#include <stdio.h>

/**
 * main - Entry point of the simple calculator skeleton
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");

	if (scanf("%d", &choice) != 1)
		return (1);

	if (choice == 0)
		printf("Bye!\n");

	return (0);
}

#include <stdio.h>

int main(void)
{
    int choice;

    do
    {
        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Quit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Bye!\n");
        }
        else if (choice < 1 || choice > 4)
        {
            printf("Invalid choice\n");
        }
        else
        {
            /* Existing calculator operations go here */
        }

    } while (choice != 0);

    return (0);
}
