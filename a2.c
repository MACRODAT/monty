#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @duxj: head of the linked list
 * @leto: line number;
 * Return: no return
 */
void _rotl(stack_t **duxj, unsigned int leto)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)leto;

	if (*duxj == NULL)
		return;

	if ((*duxj)->next == NULL)
		return;

	aux1 = (*duxj)->next;
	aux2 = *duxj;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *duxj;
	(*duxj)->next = NULL;
	(*duxj)->prev = aux2;
	*duxj = aux1;
}

/**
 * _rotr - reverse the stack
 *
 * @duxj: head of the linked list
 * @leto: line number
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
