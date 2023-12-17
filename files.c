#include "monty.h"

stack_t *head = NULL;

/**
 * handle_file - open and handle the file
 * @file_name: the file name
 * Return: void
 */
void handle_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	process_file(fd);
	fclose(fd);
}

/**
 * process_file - choose the fun you use
 * @fd: is a param
 * Return: void
 */
void process_file(FILE *fd)
{
	int line_num, format = 0;
	char *str = NULL;
	size_t len = 0;
	char *op, *value;
	const char *delim = "\n ";

	for (line_num = 1; getline(&str, &len, fd) != -1; line_num++)
	{
		if (str == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		op = strtok(str, delim);
		if (op == NULL)
			break;
		value = strtok(NULL, delim);
		if (strcmp(op, "stack") == 0)
			format = 0;
		else if (strcmp(op, "queue") == 0)
			format = 1;
		else
			process_opcode(op, value, line_num, format);
	}
	free(str);
}
/**
 * process_opcode - THis function process op codes
 * @opcode: is a param
 * @value: is a param
 * @ln: is a param
 * @format: is a param
 * Return: void
 */
void process_opcode(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", display},
		{"pint", print_top},
		{"pop", pop_from_stack},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"nop", nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list->opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * call_fun - call the function you need
 * @func: is a param
 * @op: is a param
 * @val: is a param
 * @ln: is a param
 * @format: is a param
 * Return: void
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag = 1;
	int value;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			flag = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		value = atoi(val);
		if (value == 0 && val[0] != '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		
	}
	else
		func(&head, ln);
}
