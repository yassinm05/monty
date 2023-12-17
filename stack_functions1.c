#include "main.h"

/**
 * push_to_stack - push a value to the stack
 * @new_node: is a param
 * @line_number: is a param
 * Return: void
 */
void push_to_stack(stack_t **new_node, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	if (*new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	node = head;
	head = *new_node;
	head->next = node;
	node->prev = head;
}

/**
 * display - display all the values of the stack
 * @stack: the stack that I need to print it's values
 * @line_number: is a param
 * Return: void
 */
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (*stack == NULL)
		exit(EXIT_FAILURE);
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
/**
 * pop_from_stack - pop the first value of the stack
 * @stack: is a param
 * @line_number: is a param
 * Return: void
 */
void pop_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}
/**
 * print_top - print the first item iof the stack
 * @stack: is a param
 * @line_number: is a param
 * Return: void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
