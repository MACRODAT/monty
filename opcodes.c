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
		endall("Error: malloc failed\n");
	el->n = comms.n;
	if (stack)
		el->next = *stack;
	else
		el->next = NULL;
	el->prev = NULL;
	*stack = el;
	free(el);
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

	if (!stack || !*stack)
		return;
	p = *stack;
	do {
		printf("%d\n", p->n);
	} while ((p = p->next));
}

/**
 * process_pint - fct
 * @stack: e
 * @line_number: e
*/
void process_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p = 0;
	(void) line_number;

	if (!stack || !*stack)
		PFS("L%u: can't pint, stack empty\n", line_number);
	p = *stack;
	printf("%d\n", p->n);
}
