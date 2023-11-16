#include "monty.h"

/**
 * endall - ends
 * @msg: message
*/
void endall(const char *msg)
{
	dprintf(2, "%s", msg);
	if (comms.y)
		free(comms.y);
	if (comms.x)
		fclose(comms.x);
	exit(EXIT_FAILURE);
}

/**
 * PFS - ends
 * @format: message
*/
void PFS(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	if (comms.y)
		free(comms.y);
	if (comms.x)
		fclose(comms.x);
	exit(EXIT_FAILURE);
}

/**
 * f_d - ends
 * @arr: message
*/
void f_d(stack_t **arr)
{
	stack_t *current;

	if (arr == NULL)
		return;

	while (*arr != NULL)
	{
		current = *arr;
		*arr = current->next;
		free(current);
	}
}
