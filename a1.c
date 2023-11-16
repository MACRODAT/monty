#include "monty.h"

/**
 * _div - regerg
 *
 * @duxj: heerg
 * @leto: erg
 * Return: fsenreg
 */
void _div(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *duxj;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	if ((*duxj)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	aux = (*duxj)->next;
	aux->n /= (*duxj)->n;
	_pop(duxj, leto);
}

/**
 * _mul - wefack
 *
 * @duxj: wef
 * @leto: lgg
 * Return: gweg
 */
void _mul(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *duxj;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	aux = (*duxj)->next;
	aux->n *= (*duxj)->n;
	_pop(duxj, leto);
}

/**
 * _pstr - dsded
 * @duxj: hd
 * @leto: lider
 * Return: d
 */
void _pstr(stack_t **duxj, unsigned int leto)
{
	stack_t *aux;
	(void)leto;

	aux = *duxj;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 * _mod - wefwefnt
 *
 * @duxj: werf
 * @leto: wef
 * Return: nweffwe
 */
void _mod(stack_t **duxj, unsigned int leto)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *duxj;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	if ((*duxj)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}

	aux = (*duxj)->next;
	aux->n %= (*duxj)->n;
	_pop(duxj, leto);
}
/**
 * _pchar - ergerg
 *
 * @duxj: erg
 * @leto: erg
 * Return: nreg
 */
void _pchar(stack_t **duxj, unsigned int leto)
{
	if (duxj == NULL || *duxj == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}
	if ((*duxj)->n < 0 || (*duxj)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", leto);
		free_traco();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*duxj)->n);
}
