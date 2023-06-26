#include "monty.h"
/**
 * main - function for handle the interaption.
 * @argc: the arguments count
 * @argv: arguments vector
 * Return: success or failure
 */

int main(int argc, char **argv)
{
	FILE *monty_f = NULL;
	int exit_stat;
	struct stat st;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	monty_f = fopen(argv[1], "r");
	if (!monty_f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stat(argv[1], &st);
	if (st.st_size == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	exit_stat = monty(monty_f);
	fclose(monty_f);
	return (exit_stat);
}
