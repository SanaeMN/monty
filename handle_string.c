#include "monty.h"
/**
 * _atoi - atoi function.
 * @str: string
 * Return: success
 */
int _atoi(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * readLine - function that read a file line.
 * @file: input stream
 * @l: string line to read
 * Return: string length
 */
unsigned int readLine(FILE *file, char **l)
{
	unsigned int max_size = 128, len = 0;
	char ch = getc(file);

	*l = malloc(max_size);
	if (*l == NULL)
		return (0);
	while (ch != '\n' && ch != EOF)
	{
		(*l)[len] = ch;
		len++;
		if (ch == '#')
			(*l)[len] = '\0';
		ch = getc(file);
	}
	if (ch == '\n')
		(*l)[len] = ch, len++;
	(*l)[len] = '\0';
	if (len == 0)
	{
		free(*l);
		*l = NULL;
	}
	return (len);
}
/**
 * _calloc - function allocates memory for an array, using malloc.
 *
 * @nmemb: number of members
 * @size: size allocate
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		ptr[i] = 0;
	return (ptr);
}
/**
 * handle_within - function that check the within.
 * @ch: character
 * @str: string
 * Return: boolean
 */
int handle_within(char ch, char *str)
{
	if (*str == '\0')
		return (ch == *str);
	return (ch == *str ? 1 : handle_within(ch, str + 1));
}
/**
 * _strtok - function handle the string tokens.
 * @str: string
 * Return: tokens set
 */
char **_strtok(char *str)
{
	char **tokens;
	size_t j = 0, i, len = strlen(str) + 1;
	int check = 1, y = 0;

	tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; str[i]; i++)
	{
		if (handle_within(str[i], DELIMS))
		{
			if (!check)
			{
				tokens[y++][j] = '\0';
				tokens[y] = (char *)_calloc(len, sizeof(char));
				if (!tokens[y])
					_free(tokens);
			}
			check = 1;
			j = 0;
		}
		else
		{
			tokens[y][j++] = str[i];
			check = 0;
		}
	}
	if (check)
	{
		free(tokens[y]);
		tokens[y] = NULL;
	}
	else
		tokens[y][j] = '\0';
	return (tokens);
}
