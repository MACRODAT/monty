#include "monty.h"

/**
 * _push - psefck
 *
 * @duxj: hesdf
 * @leto: sdf
 * Return: sd
 */
void _push(stack_t **duxj, unsigned int leto)
{
	int n, j;

	if (!traco.arg)
	{
		dprintf(2, "L%u: ", leto);
		dprintf(2, "usage: push integer\n");
		free_traco();
		exit(EXIT_FAILURE);
	}

	for (j = 0; traco.arg[j] != '\0'; j++)
	{
		if (!isdigit(traco.arg[j]) && traco.arg[j] != '-')
		{
			dprintf(2, "L%u: ", leto);
			dprintf(2, "usage: push integer\n");
			free_traco();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(traco.arg);

	if (traco.lifo == 1)
		add_dnodeint(duxj, n);
	else
		add_dnodeint_end(duxj, n);
}


/**
 * _pint - prints the value at the top of the stack
 *
 * @duxj: head of the linked list
 * @leto: line number
 * Return: no return
 */
void _pint(stack_t **duxj, unsigned int leto)
{
	(void)leto;

	if (*duxj == NULL)
	{
		dprintf(2, "L%u: ", leto);
		dprintf(2, "can't pint, stack empty\n");
		free_traco();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*duxj)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @duxj: head of the linked list
 * @leto: line number
 * Return: no return
 */
void _pop(stack_t **duxj, unsigned int leto)
{
	stack_t *dedj;

	if (duxj == NULL || *duxj == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}
	dedj = *duxj;
	*duxj = (*duxj)->next;
	free(dedj);
}


/**
 * _pall - ew
 * @duxj: hewfist
 * @leto: wewew
 * Return: fwe
 */
void _pall(stack_t **duxj, unsigned int leto)
{
	stack_t *dedj;
	(void)leto;

	dedj = *duxj;

	while (dedj)
	{
		printf("%d\n", dedj->n);
		dedj = dedj->next;
	}
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @duxj: head of the linked list
 * @leto: line number
 * Return: no return
 */
void _swap(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *dedj = NULL;

	dedj = *duxj;

	for (; dedj != NULL; dedj = dedj->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	dedj = *duxj;
	*duxj = (*duxj)->next;
	dedj->next = (*duxj)->next;
	dedj->prev = *duxj;
	(*duxj)->next = dedj;
	(*duxj)->prev = NULL;
}
