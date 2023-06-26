#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	int (*f)(char **op_tk, stack_t **stack, unsigned int line_number);
} instruction_t;
int monty(FILE *f);
int _atoi(char *s);
unsigned int args_count(char **args);
char **_strtok(char *s);
void free_stack(stack_t **stack);
int create_stack(stack_t **stack);
void _free(char **tks);
unsigned int readLine(FILE *file, char **l);
int (*function_selector(char *))(char **, stack_t**, unsigned int);
/*functions*/
int push(char **op_tk, stack_t **stack, unsigned int line_number);
int pall(char **op_tk, stack_t **stack, unsigned int line_number);
int pint(char **op_tk, stack_t **stack, unsigned int line_number);
int pop(char **op_tk, stack_t **stack, unsigned int line_number);
int swap(char **op_tk, stack_t **stack, unsigned int line_number);
int add(char **op_tk, stack_t **stack, unsigned int line_number);
int nop(char **op_tk, stack_t **stack, unsigned int line_number);
int sub(char **op_tk, stack_t **stack, unsigned int line_number);
int _div(char **op_tk, stack_t **stack, unsigned int line_number);
int mul(char **op_tk, stack_t **stack, unsigned int line_number);
int mod(char **op_tk, stack_t **stack, unsigned int line_number);
int pchar(char **op_tk, stack_t **stack, unsigned int line_number);
int pstr(char **op_tk, stack_t **stack, unsigned int line_number);
int rotl(char **op_tk, stack_t **stack, unsigned int line_number);
int rotr(char **op_tk, stack_t **stack, unsigned int line_number);
int stack(char **op_tk, stack_t **stack, unsigned int line_number);
int queue(char **op_tk, stack_t **stack, unsigned int line_number);
#endif
