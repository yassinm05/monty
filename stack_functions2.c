#include "monty.h"
/**
 * swap_nodes - swap 2 nodes
 * @stack:is a param
 * @line_number: is a param
 * Return: void
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "swap");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "swap");
		exit(EXIT_FAILURE);
	}
	node = (*stack)->next;
	(*stack)->next = node->next;
	if (node->next != NULL)
		node->next->prev = *stack;
	node->next = *stack;
	(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}
/**
 * add_nodes - add the top 2 elements of the top 2 nodes
 * @stack: is a param
 * @line_number: is a param
 * Return: void
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "add");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "add");
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: is a param
 * @line_number: is a param;
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
