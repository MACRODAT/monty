#include "monty.h"

global_t traco;

/**
 * free_traco - frees the global variables
 *
 * Return: no return
 */
void free_traco(void)
{
	free_dlistint(traco.head);
	free(traco.buffer);
	fclose(traco.fd);
}

/**
 * start_traco - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_traco(FILE *fd)
{
	traco.lifo = 1;
	traco.cont = 1;
	traco.arg = NULL;
	traco.head = NULL;
	traco.fd = fd;
	traco.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_traco(fd);
	nlines = getline(&traco.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(traco.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", traco.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_traco();
				exit(EXIT_FAILURE);
			}
			traco.arg = _strtoky(NULL, " \t\n");
			f(&traco.head, traco.cont);
		}
		nlines = getline(&traco.buffer, &size, fd);
		traco.cont++;
	}

	free_traco();

	return (0);
}
