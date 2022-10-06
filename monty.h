#ifndef _MONTY_HOL
#define _MONTY_HOL

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

#define LIMITER " \n"


/* Structures Doubly linked lists */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes basic operations */

void pall(stack_t **head, unsigned int counter);
void push(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);

/* Selector structure */
void select_func(stack_t **head, char *token, unsigned int counter);

/* Free memory */
void free_all(stack_t **head);

#endif /* _MONTY_HOL */
