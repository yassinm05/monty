#include "main.h"
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
	return (0);
}
