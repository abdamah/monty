#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void - Nothing
 **/

void swap(stack_t **head, unsigned int counter)
{
	int tmp; /* Temporal variable for swap */

	/* Verify If the stack contains less than two elements */
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
 * nop - Doesn’t do anything.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void - Nothing
 **/
void nop(stack_t **head, unsigned int counter)
{
	/* Attribute unused*/
	(void) head;
	(void) counter;
}
