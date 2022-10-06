#include "monty.h"

/**
* add - Adds the top two elements of the stack.
* @head: Head of the list
* @counter: Number of the line
* Return: Void - Nothing
**/
void add(stack_t **head, unsigned int counter)
{
	int add_elem;

	/* Verify If the stack contains less than two elements */
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	add_elem = (*head)->n;
	add_elem += (*head)->next->n;
	pop(head, counter);
	(*head)->n = add_elem;
}

/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void - Nothing
 **/

void sub(stack_t **head, unsigned int counter)
{
	/* Verify If the stack contains less than two elements */
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * mul -  multiplies the second top element of the stack with
 * the top element of the stack.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void - Nothing
 **/

void mul(stack_t **head, unsigned int counter)
{
	/* Verify If the stack contains less than two elements */
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * _div - This function subtracts the top element of the stack from
 * the second top element of the stack.
 * @head: The head of the Stack.
 * @counter: Number of the line.
 * Return: Void - Nothing.
 **/
void _div(stack_t **head, unsigned int counter)
{
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
