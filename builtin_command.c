#include "shell.h"

/**
 * exit_Shell - function to terminate the program.
 * @command: Double pointer to the array of commands
 */
void exit_Shell(char **command)
{
	free_command(command);
	exit(EXIT_SUCCESS);
}
/**
 * print_env - built in function to print environment.
 * @command: Double pointer to the array of commands
 */
void print_env(char **command)
{
	char **env = environ;
	(void)command;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
