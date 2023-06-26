#include "monty.h"
/**
 * free_stack - function that free a memory stack.
 * @stack: stack
 * return: none
 */
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;

	while (*stack)
	{
		node = (*stack)->next;
		free(*stack);
		*stack = node;
	}
}

/**
 * create_stack - function that create a memory stack.
 * @stack: stack
 * Return: none
 */
int create_stack(stack_t **stack)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	node->n = STACK;
	node->prev = NULL;
	node->next = NULL;
	*stack = node;
	return (EXIT_SUCCESS);
}
