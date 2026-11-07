#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the size of the triangle
 */
void print_triangle(int size)
{
	int row;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	row = 1;
	while (row <= size)
	{
		col = 1;
		while (col <= size)
		{
			if (col <= size - row)
				_putchar(' ');
			else
				_putchar('#');
			col++;
		}
		_putchar('\n');
		row++;
	}
}
