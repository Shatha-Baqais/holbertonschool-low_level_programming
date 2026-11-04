#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the size of the table (0 to 15)
 */
void print_times_table(int n)
{
	int row;
	int col;
	int p;

	if (n < 0 || n > 15)
		return;
	row = 0;
	while (row <= n)
	{
		col = 0;
		while (col <= n)
		{
			p = row * col;
			if (col == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 100)
					_putchar(' ');
				else
					_putchar(p / 100 + '0');
				if (p < 10)
					_putchar(' ');
				else
					_putchar(p / 10 % 10 + '0');
				_putchar(p % 10 + '0');
			}
			col++;
		}
		_putchar('\n');
		row++;
	}
}
