#include "monty.h"

/**
 *add_dnodeint_end - fwe
 *@head: efw
 *@n: fwe
 *Return: aefw
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *kjsd, *aux;

	if (head == NULL)
		return (NULL);
	kjsd = malloc(sizeof(stack_t));
	if (!kjsd)
	{
		dprintf(2, "Error: malloc failed\n");
		free_traco();
		exit(EXIT_FAILURE);
	}
	kjsd->n = n;
	if (*head == NULL)
	{
		kjsd->next = *head;
		kjsd->prev = NULL;
		*head = kjsd;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	kjsd->next = aux->next;
	kjsd->prev = aux;
	aux->next = kjsd;
	return (aux->next);
}

/**
 * free_dlistint - fwe
 *
 * @head: weffwefwef
 * Return: wef
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}


/**
 *add_dnodeint - weffwefew
 *@head: fweffefw
 *@n: efwefwe
 *Return: efwfwe
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *kjsd;

	if (head == NULL)
		return (NULL);
	kjsd = malloc(sizeof(stack_t));
	if (!kjsd)
	{
		dprintf(2, "Error: malloc failed\n");
		free_traco();
		exit(EXIT_FAILURE);
	}
	kjsd->n = n;
	if (*head == NULL)
	{
		kjsd->next = *head;
		kjsd->prev = NULL;
		*head = kjsd;
		return (*head);
	}
	(*head)->prev = kjsd;
	kjsd->next = (*head);
	kjsd->prev = NULL;
	*head = kjsd;
	return (*head);
}
