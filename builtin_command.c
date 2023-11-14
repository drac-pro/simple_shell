#include "shell.h"

/**
 * exitShell - function to terminate the program.
 */
void exitShell(char **command)
{
	free_command(command);
	exit(EXIT_SUCCESS);
}
/**
 * print_env - built in function to print environment 
 */
void print_env(void)
{
	char **env = environ;
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
