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


/**
 * _mod - Computes the modulus of the second value from the
 *             top of a head_t linked list  by the top value.
 * @head: A pointer to the top mode node of a head_t linked list.
 * @counter: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _mod(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*head)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
		return;
	}

	(*head)->next->next->n %= (*head)->next->n;
	pop(head, counter);
}
