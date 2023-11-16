#include "monty.h"

/**
 * endall - ends
 * @msg: message
*/
void endall(const char *msg)
{
	fprintf(stderr, "%s", msg);
	exit(EXIT_FAILURE);
}

/**
 * printFormattedString - ends
 * @format: message
*/
void printFormattedString(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}
