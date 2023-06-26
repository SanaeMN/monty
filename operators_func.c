#include "monty.h"
/**
 * add - function adds the top two elements of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @number: integer
 * Return: success
 */
int add(char **op_tk, stack_t **stack, unsigned int number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n += (*stack)->next->n;
	return (pop(op_tk, stack, number));
}

/**
 * sub - function sub top element from the second top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int sub(char **op_tk, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	return (pop(op_tk, stack, line_number));
}

/**
 * _div - function div the second top element by the top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int _div(char **op_tk, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	return (pop(op_tk, stack, line_number));
}

/**
 * mul - function mul the second top element with the top of the stack.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int mul(char **op_tk, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	return (pop(op_tk, stack, line_number));
}
/**
 * mod - function computes mod of the second top element by the top.
 * @op_tk: tokens
 * @stack: stack
 * @line_number: integer
 * Return: success
 */
int mod(char **op_tk, stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	return (pop(op_tk, stack, line_number));
}
