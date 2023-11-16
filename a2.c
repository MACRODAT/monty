#include "monty.h"

/**
 * _rotr - wef
 *
 * @duxj: heewf liwefefwst
 * @leto: fwe
 * Return: no return
 */
void _rotr(stack_t **duxj, unsigned int leto)
{
	stack_t *aux = NULL;
	(void)leto;

	if (*duxj == NULL)
		return;

	if ((*duxj)->next == NULL)
		return;

	aux = *duxj;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *duxj;
	aux->prev = NULL;
	(*duxj)->prev = aux;
	*duxj = aux;
}

/**
 * _rotl - wef weffwe
 *
 * @duxj: weft
 * @leto: lfew;
 * Return: eee
 */
void _rotl(stack_t **duxj, unsigned int leto)
{
	stack_t *hsjkjkkhdjk = NULL;
	stack_t *tgsd = NULL;
	(void)leto;

	if (*duxj == NULL)
		return;

	if ((*duxj)->next == NULL)
		return;

	hsjkjkkhdjk = (*duxj)->next;
	tgsd = *duxj;

	for (; tgsd->next != NULL; tgsd = tgsd->next)
		;

	hsjkjkkhdjk->prev = NULL;
	tgsd->next = *duxj;
	(*duxj)->next = NULL;
	(*duxj)->prev = tgsd;
	*duxj = hsjkjkkhdjk;
}
