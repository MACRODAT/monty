#include "monty.h"

/**
 * endall - ends
 * @msg: message
*/
void endall(const char *msg)
{
	dprintf(2, "%s", msg);
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
	exit(EXIT_FAILURE);
}
