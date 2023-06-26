#include "monty.h"
/**
 * rotl - function rotates the stack to the top.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int rotl(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *top, *down;

	(void)line_number;
	(void)op_tk;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return (EXIT_SUCCESS);
	top = (*stack)->next;
	down = (*stack)->next;
	while (down->next != NULL)
		down = down->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	down->next = top;
	top->next = NULL;
	top->prev = down;
	return (EXIT_SUCCESS);
}
/**
 * rotr - function rotates the stack to the bottom.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int rotr(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *up, *bottom;

	(void)line_number;
	(void)op_tk;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return (EXIT_SUCCESS);
	up = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = up;
	up->prev = bottom;
	return (EXIT_SUCCESS);
}
