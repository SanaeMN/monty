#include "monty.h"
/**
 * push - function pushes an element to the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int push(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_st = malloc(sizeof(stack_t));

	if (new_st == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (args_count(op_tk) < 2 || _atoi(op_tk[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new_st);
		return (EXIT_FAILURE);
	}
	new_st->n = atoi(op_tk[1]);
	if ((*stack)->n == STACK)
	{
		temp = (*stack)->next;
		new_st->prev = *stack;
		new_st->next = temp;
		if (temp)
			temp->prev = new_st;
		(*stack)->next = new_st;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_st->prev = temp;
		new_st->next = NULL;
		temp->next = new_st;
	}
	return (EXIT_SUCCESS);
}
/**
 * pall - function  prints all the values on the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pall(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void)line_number;
	(void)op_tk;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
/**
 * pint - function prints the value at the top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pint(char **op_tk, stack_t **stack, unsigned int line_number)
{
	(void)op_tk;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
	return (EXIT_SUCCESS);
}
/**
 * pop - function removes the top element of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pop(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *next_p = NULL;

	(void)op_tk;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}
	next_p = (*stack)->next->next;
	free((*stack)->next);
	if (next_p)
		next_p->prev = *stack;
	(*stack)->next = next_p;
	return (EXIT_SUCCESS);
}

/**
 * swap - function swaps the top two elements of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int swap(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)op_tk;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
	return (EXIT_SUCCESS);
}
