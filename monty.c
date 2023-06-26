#include "monty.h"

/**
 * free_tokens - function that free the tokens.
 * @op_tk: tokens
 * @l: string
 * @free_cdt: condition
 * Return: none
 */
void free_tokens(char **op_tk, char *l, int free_cdt)
{
	if (free_cdt == 0)
	{
		if (l)
			free(l);
		if (op_tk)
			_free(op_tk);
	}
}
/**
 * _free - function free.
 * @tks: operation tokens
 * Return: none
 */
void _free(char **tks)
{
	int i = 0;

	if (tks == NULL)
		return;
	for (i = 0; tks[i]; i++)
		free(tks[i]);
	free(tks);
}
/**
 * args_count - function count the arguments.
 * @args: arguments
 * Return: argc
 */
unsigned int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
/**
 * monty - funtion of monty file.
 * @f: monty file
 * Return: success
 */
int monty(FILE *f)
{
	unsigned int nbr = 0, exit_stat = EXIT_SUCCESS, free_cndtn = 0;
	char *l = NULL, **op_tk = NULL;
	stack_t *stack = NULL;
	int (*func)(char **, stack_t**, unsigned int);

	if (create_stack(&stack) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while (readLine(f, &l) > 0)
	{
		nbr++, free_cndtn = 0;
		if (l[0] == '#' || l[0] == '\n')
		{
			free(l);
			continue;
		}
		op_tk = _strtok(l);
		if (args_count(op_tk) == 0 || op_tk[0][0] == '#'
			|| (op_tk[1] && op_tk[1][0] == '#'))
		{
			free_tokens(op_tk, l, free_cndtn);
			continue;
		}
		func = function_selector(op_tk[0]);
		if (func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				nbr, op_tk[0]);
			exit_stat = EXIT_FAILURE;
			break;
		}
		if (func(op_tk, &stack, nbr) == EXIT_FAILURE)
		{
			exit_stat = EXIT_FAILURE;
			break;
		}
		free(l), _free(op_tk), free_cndtn = 1;
	}
	free_tokens(op_tk, l, free_cndtn), free_stack(&stack);
	return (exit_stat);
}
