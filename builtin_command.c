#include "shell.h"

/**
 * exitShell - function to terminate the program.
 */
void exit_shell(char **command)
{
	free_command(command);
	exit(EXIT_SUCCESS);
}
/**
 * print_env - built in function to print environment 
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
