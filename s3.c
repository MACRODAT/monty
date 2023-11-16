#include "monty.h"
/**
 * _calloc - ertg
 * @szer: ger
 * @slighter: reger
 * Return: ger
 */
void *_calloc(unsigned int slighter, unsigned int szer)
{
	void *p = NULL;
	unsigned int i;

	if (slighter == 0 || szer == 0)
	{
		return (NULL);
	}
	p = malloc(slighter * szer);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (slighter * szer); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * _realloc - change the szer and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_szer: old number of bytes
 * @new_szer: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_szer, unsigned int new_szer)
{
	char *p = NULL;
	unsigned int i;

	if (new_szer == old_szer)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_szer);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_szer == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_szer > old_szer)
	{
		p = malloc(new_szer);
		if (!p)
			return (NULL);
		for (i = 0; i < old_szer; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_szer);
		if (!p)
			return (NULL);
		for (i = 0; i < new_szer; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
