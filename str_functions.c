#include "monty.h"
/**
 * _strcmp - fwef
 * @s1: fwe
 * @s2: tfwed
 * Return: fwe
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * fuk_betty - erge
 * @s: gre
 * @c: erger
 * Return: ger
 */
int fuk_betty(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - ger
 * @s: ger
 * @d: ger
 * Return: ger
 */
char *_strtoky(char *s, char *d)
{
	static char *bullshit;
	int i = 0, j = 0;

	if (!s)
		s = bullshit;
	while (s[i] != '\0')
	{
		if (fuk_betty(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			bullshit = s + i + 1;
			*bullshit = '\0';
			s = s + j;
			return (s);
		}
		else if (fuk_betty(d, s[i]) == 0 && fuk_betty(d, s[i + 1]) == 0)
			i++;
		else if (fuk_betty(d, s[i]) == 0 && fuk_betty(d, s[i + 1]) == 1)
		{
			bullshit = s + i + 1;
			*bullshit = '\0';
			bullshit++;
			s = s + j;
			return (s);
		}
		else if (fuk_betty(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
