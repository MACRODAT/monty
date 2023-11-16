#include "monty.h"

/**
 * process_line - process a line
 * @s: line
 * @st: e
 * @line_number: e
 * Return: rr
*/
int process_line(char *s, stack_t **st, unsigned int line_number)
{
	char **tokens;
	int i = 0, flag = 0, ind = 0, count = 0, needs_completion = 0;
	instruction_t stack[] = {
		{"push", process_push, 1},
		{"pall", process_pall, 0},
		{"", NULL, 0}
	};
	instruction_t *p;
	void (*f)(stack_t **stack, unsigned int line_number);

	f = NULL, tokens = _splitString(s, " \t\n$", &count);
	while (i < count)
	{
		p = stack;
		while (p && p->f && !flag)
		{
			if (str_cmp(p->opcode, tokens[i]) == 0)
			{
				f = p->f, needs_completion = p->needs_completion;
				break;
			}
			p++, ind = (_strlen(tokens[i]) > 0) ? 1 : ind;
		}
		if (f)
			break;
		i++;
	}
	if (!f)
	{
		if (!ind)
			return (0);
		printFormattedString("L%u: unknown instruction %s\n", line_number, s);
	}
	return (process_line_cont(i, flag, ind,
		tokens, f, needs_completion, st, line_number));
}

/**
 * process_line_cont - process a line
 * @flag: line
 * @ind: line
 * @tokens: line
 * @needs_completion: line
 * @st: e
 * @i: e
 * @f: e
 * @line_number: e
 * Return: rr
*/
int process_line_cont(int i, int flag, int ind, char **tokens,
	void (*f)(stack_t **stack, unsigned int line_number),
	int needs_completion, stack_t **st, unsigned int line_number)
{
	i++;
	if (needs_completion > 0)
	{
		while (!flag && tokens[i])
			if (str_cmp(tokens[i], "0") == 0 && !flag)
				ind = 0, flag = 1;
			else
				ind = atoi(tokens[i++]), flag = (ind == 0) ? 0 : 1;

		if (!flag)
			printFormattedString("L%u: usage: push integer\n", line_number);
		comms.n = ind;
	}
	comms.n = ind, f(st, line_number);
	return (0);
}
