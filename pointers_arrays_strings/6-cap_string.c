#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: the string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i;
	int j;
	int new_word;
	char *sep = " \t\n,;.!?\"(){}";

	new_word = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (new_word && s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('a' - 'A');
		new_word = 0;
		j = 0;
		while (sep[j] != '\0')
		{
			if (s[i] == sep[j])
				new_word = 1;
			j++;
		}
		i++;
	}
	return (s);
}
