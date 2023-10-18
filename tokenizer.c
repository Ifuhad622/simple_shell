#include "shell.h"

/**
 * **strtow - to split a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or 0 on failure
 */

char **strtow(char *str, char *d)
{
	int w, x, y, z, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!z)
		z = " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!is_delim(str[w], z) && (is_delim(str[w + 1], w) || !str[w + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, x = 0; x < numwords; x++)
	{
		while (is_delim(str[w], z))
			w++;
		y = 0;
		while (!is_delim(str[w + y], z) && str[w + y])
			y++;
		s[x] = malloc((z + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[x][m] = str[w++];
		s[x][m] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
 * **strtow2 - to splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

