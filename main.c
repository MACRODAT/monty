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
 * str_cmp - comparer
 * @str1: s
 * @str2: s
 * Return: rn
*/
int str_cmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
	}
	if (str1[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * process_push - fct
 * @stack: e
 * @line_number: e
*/
void process_push(stack_t **stack, unsigned int line_number)
{

}

/**
 * process_pall - fct
 * @stack: e
 * @line_number: e
*/
void process_pall(stack_t **stack, unsigned int line_number)
{

}


/**
 * process_line - process a line
 * @s: line
 * @stack: e
 * @line_number: e
 * Return: rr
*/
int process_line(char *s, stack_t **st, unsigned int line_number)
{
	char *tokens;
	int i = 0, flag = 0, ind = 0;
	instruction_t stack[] = {
		{"push", process_push},
		{"pall", process_pall},
		{"", NULL}
	};
	instruction_t *p;
	void (*f)(stack_t **stack, unsigned int line_number);

	f = NULL;

	tokens = _strtoky(s, " \t\n");
	while (tokens[i])
	{
		p = stack;
		while (p && p->f && !flag)
		{
			if (str_cmp(p->opcode, tokens[i]) == 0)
			{
				f = p->f;
				break;
			}
			p++;
		}
		i++;
	}

	if (!f)
	{
		printf("L%u: unknown instruction %s\n", line_number, s);
		exit(EXIT_FAILURE);
	}
	i++;
	while (tokens[i])
	{
		if (str_cmp(tokens[i], "0") == 0 && !flag)
		{
			ind = 0;
			flag = 1;
		}
		else
		{
			ind = atoi(tokens);
			if (!ind)
				flag = 0;
			else
				flag = 1;
		}
		i++;
	}

	if (!flag)
	{
		printf("L%u: unknown instruction %s\n", line_number, s);
		exit(EXIT_FAILURE);
	}
	comms.n = ind;
	f(st, line_number);

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
	ssize_t nlines = 0;
	char *line;
	int ln = 1;
	stack_t **st;

	if (argc == 1 || argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
	return (0);
}
