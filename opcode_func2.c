#include "monty.h"
/**
 * nop - function doesn’t do anything.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int nop(char **op_tk, stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	(void)op_tk;
	return (EXIT_SUCCESS);
}
/**
 * pchar - function prints the char at the top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @number: integer
 * Return: success
 */
int pchar(char **op_tk, stack_t **stack, unsigned int number)
{
	(void)op_tk;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", number);
		return (EXIT_FAILURE);
	}
	printf("%c\n", (char)(*stack)->next->n);
	return (EXIT_SUCCESS);
}
/**
 * pstr - function prints the string starting at the top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int pstr(char **op_tk, stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void)line_number;
	(void)op_tk;
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
/**
 * stack - function ets the format of the data to a stack (LIFO).
 * @op_tk: tokens
 * @stack: stack
 * @number: integer
 * Return: success
 */
int stack(char **op_tk, stack_t **stack, unsigned int number)
{
	(void)number;
	(void)op_tk;
	(*stack)->n = STACK;
	return (EXIT_SUCCESS);
}
/**
 * queue - function sets the format of the data to a queue (FIFO).
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int queue(char **op_tk, stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)op_tk;
	(*stack)->n = QUEUE;
	return (EXIT_SUCCESS);
}
