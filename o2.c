#include "monty.h"



/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @duxj: head of the linked list
 * @leto: line number;
 * Return: no return
 */
void _stack(stack_t **duxj, unsigned int leto)
{
	(void)duxj;
	(void)leto;

	traco.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @duxj: head of the linked list
 * @leto: line number;
 * Return: no return
 */
void _add(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *duxj;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	aux = (*duxj)->next;
	aux->n += (*duxj)->n;
	_pop(duxj, leto);
}

/**
 * _nop - wef
 *
 * @duxj: wfe
 * @leto: fwe
 * Return: fwe
 */
void _nop(stack_t **duxj, unsigned int leto)
{
	(void)duxj;
	(void)leto;
}

/**
 * _queue - swef
 *
 * @duxj: wef
 * @leto: fwe
 * Return: fwe
 */
void _queue(stack_t **duxj, unsigned int leto)
{
	(void)duxj;
	(void)leto;

	traco.lifo = 0;
}
