#include "monty.h"


/**
 * _sub - gerk
 *
 * @duxj: hg
 * @leto: ldfger;
 * Return: ndfg
 */
void _sub(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *duxj;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	aux = (*duxj)->next;
	aux->n -= (*duxj)->n;
	_pop(duxj, leto);
}

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t indestweruct[] = {
		{"push", _push},
		{"pint", _pint},
		{"pop", _pop},
		{"pall", _pall},
		{"queue", _queue},
		{"add", _add},
		{"swap", _swap},
		{"sub", _sub},
		{"stack", _stack},
		{"div", _div},
		{"mul", _mul},
		{"nop", _nop},
		{"mod", _mod},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"pchar", _pchar},
		{NULL, NULL}
	};
	int i;

	for (i = 0; indestweruct[i].opcode; i++)
	{
		if (_strcmp(indestweruct[i].opcode, opc) == 0)
			break;
	}

	return (indestweruct[i].f);
}
