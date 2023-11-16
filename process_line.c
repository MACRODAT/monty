#include "monty.h"

/**
 * process_line - process a line
 * @s: line
 * @stack: e
 * @line_number: e
 * Return: rr
*/
int process_line(char *s, stack_t **st, unsigned int line_number)
{
	char **tokens;
	int i = 0, flag = 0, ind = 0, count = 0;
	int needs_completion = 0;
	instruction_t stack[] = {
		{"push", process_push, 1},
		{"pall", process_pall, 0},
		{"", NULL, 0}
	};
	instruction_t *p;
	void (*f)(stack_t **stack, unsigned int line_number);

	f = NULL;

	tokens = _splitString(s, " \t\n$", &count);
	while (i < count)
	{
		p = stack;
		while (p && p->f && !flag)
		{
			if (str_cmp(p->opcode, tokens[i]) == 0)
			{
				f = p->f;
				needs_completion = p->needs_completion;
				break;
			}
			p++;
		}
		if (f)
			break;
		i++;
	}

	if (!f)
	{
		printf("L%u: unknown instruction %s\n", line_number, s);
		exit(EXIT_FAILURE);
	}
	i++;
	if (needs_completion > 0)
	{
		while (!flag && tokens[i])
		{
			if (str_cmp(tokens[i], "0") == 0 && !flag)
			{
				ind = 0;
				flag = 1;
			}
			else
			{
				ind = atoi(tokens[i]);
				if (!ind)
					flag = 0;
				else
					flag = 1;
			}
			i++;
		}

		if (!flag)
		{
			printf("L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		comms.n = ind;
	}
	comms.n = ind;
	f(st, line_number);

	return (0);
}
