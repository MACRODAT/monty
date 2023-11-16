#include "monty.h"

commons_t comms;

/**
 * is_digit - is it digit
 * @c: char
 * Return: 0
*/
int is_digit(char *c)
{
	int ascii = (int) *c;

	if ((ascii >= '0') && (ascii <= '9'))
		return (1);
	return (0);
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
	char *line;
	int ln = 1, nlines = 0;
	stack_t **st;

	st = malloc(sizeof(stack_t *));
	if (!st)
		endall("Error: malloc failed\n");
	*st = 0;
	if (argc == 1 || argc > 2)
		endall("USAGE: monty file\n");

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * 1000000);
	if (!line)
		endall("Error: malloc failed\n");
	comms.n = -1;
	comms.o = 0;
	comms.x = 0;
	comms.y = 0;
	nlines = getline(&line, &size, fd);
	while (nlines != -1)
	{
		process_line(line, st, ln);
		nlines = getline(&line, &size, fd);
		ln++;
	}
	fclose(fd);
	free(st);
	return (0);
}
