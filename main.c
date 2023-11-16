#include "monty.h"

commons_t comms;

/**
 * is_digit - is it digit
 * @c: char
 * Return: 0
*/
int is_digit(char *c)
{
	char *p = c;
	int ascii;

	if (!p)
		return (0);
	if (*p == '-')
		p++;
	while (*p)
	{
		ascii = (int) *p;
		if ((ascii < '0') || (ascii > '9'))
			return (0);
		p++;
	}
	return (1);
}

/**
 * main - entry
 * @argc: args
 * @argv: args
 * Return: 1
*/
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	char *line = 0;
	int ln = 1, nlines = 0;
	stack_t **st = 0;

	st = malloc(sizeof(stack_t *));
	if (!st)
		endall("Error: malloc failed\n");
	*st = 0;
	if (argc == 1 || argc > 2)
	{
		free(st);
		endall("USAGE: monty file\n");
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		free(st);
		PFS("Error: Can't open file %s\n", argv[1]);
	}
	line = malloc(sizeof(char) * 1000);
	if (!line)
	{
		free(st);
		endall("Error: malloc failed\n");
	}
	comms.n = -1;
	comms.o = 0, comms.x = 0, comms.y = 0;
	nlines = getline(&line, &size, fd);
	while (nlines != -1)
	{
		process_line(line, st, ln);
		nlines = getline(&line, &size, fd), ln++;
	}
	fclose(fd), free(st), free(line);
	return (0);
}
