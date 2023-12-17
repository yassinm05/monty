#include "monty.h"
/**
 * main - entry point
 * @argc: is a param
 * @argv: is a param
 * Return: alwayes 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	handle_file(argv[1]);
	free_nodes();
	return (0);
}
/**
 * create_node - create a new node
 * @n: the value of the node
 * Return: a pointer to a new node
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = n;
	return (new_node);
}
/**
 * free_nodes - free the nodes in stack
 *
 * Return: nothing
 */
void free_nodes(void)
{
	stack_t *node;
	if (head == NULL)
	{
		return;
	}
	else
	{
		while (head != NULL)
		{
			node = head;
			head = head->next;
			free(node);
		}
	}
}
