#include "shell.h"

/**
<<<<<<< HEAD
 * exit_shell - function to terminate the program
 *
 * @command: command to be executed
 *
 * Return: void
=======
 * exit_Shell - function to terminate the program.
 * @command: Double pointer to the array of commands
>>>>>>> 2eb0d84bceca5d7d0f2c14f81f8f48668b70d7aa
 */
void exit_Shell(char **command)
{
	free_command(command);
	exit(EXIT_SUCCESS);
}
/**
<<<<<<< HEAD
 * print_env - built in function to print environment
 *
 * @command: command to be executed
 *
 * Return: void
=======
 * print_env - built in function to print environment.
 * @command: Double pointer to the array of commands
>>>>>>> 2eb0d84bceca5d7d0f2c14f81f8f48668b70d7aa
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
