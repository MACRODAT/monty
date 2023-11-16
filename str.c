#include "monty.h"

/**
 * search_for - ee
 * @s: e
 * @c: e
 * Return: 10
 */
int search_for(char *s, char c)
{
	int indexer = 0;

	while (s[indexer] != '\0')
	{
		if (s[indexer] == c)
		{
			break;
		}
		indexer++;
	}
	if (s[indexer] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - fdt
 * @s: dd
 * @d: dsk
 * Return: ds partidtion
 */
char *_strtoky(char *s, char *d)
{
	static char *hhd;
	int i = 0, j = 0;

	if (!s)
		s = hhd;
	while (s[i] != '\0')
	{
		if (search_for(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			hhd = s + i + 1;
			*hhd = '\0';
			s = s + j;
			return (s);
		}
		else if (search_for(d, s[i]) == 0 && search_for(d, s[i + 1]) == 0)
			i++;
		else if (search_for(d, s[i]) == 0 && search_for(d, s[i + 1]) == 1)
		{
			hhd = s + i + 1;
			*hhd = '\0';
			hhd++;
			s = s + j;
			return (s);
		}
		else if (search_for(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}