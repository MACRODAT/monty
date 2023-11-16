#include "monty.h"


/**
 * process_push - fct
 * @stack: e
 * @line_number: e
*/
void process_push(stack_t **stack, unsigned int line_number)
{
	stack_t *el;
	(void) line_number;

	el = malloc(sizeof(stack_t));
	if (!el)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	el->n = comms.n;
	if (stack)
		el->next = *stack;
	else
		el->next = NULL;
	el->prev = NULL;
	*stack = el;
}

/**
 * process_pall - fct
 * @stack: e
 * @line_number: e
*/
void process_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = 0;
	(void) line_number;

	if (!stack)
		return;
	p = *stack;
	do {
		printf("%d", p->n);
	} while ((p = p->next));
}
