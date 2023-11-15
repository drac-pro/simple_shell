#include "shell.h"

/**
 * exit_shell - function to terminate the program
 *
 * @command: command to be executed
 *
 * Return: void
 */
void exit_shell(char **command)
{
	free_command(command);
	exit(EXIT_SUCCESS);
}
/**
 * print_env - built in function to print environment
 *
 * @command: command to be executed
 *
 * Return: void
 */
void print_env(char **command)
{
	int i = 0;
	char **envp = environ;

	if (strcmp(command[0], "env") == 0)
	{
		for (i = 0; envp[i] != NULL; i++)
			puts(envp[i]);
	}
}
