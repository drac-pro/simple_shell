#include "shell.h"

/**
 * main - simple unix command interpreter
 *
 * Return: 0 (success)
 */
int main(void)
{
	int status = 0, i = 0;

while (1)
{
	int num_words;
	char *input = _getline();

	if (input)
	{
		char **command;
		pid_t child_pid;

		command = input_token(input, &num_words);
		child_pid = fork_process();
		if (child_pid == 0)
			exec_execve(command);
		else
			exec_wait(child_pid, num_words, &status);
		while (command[i] != NULL)
			free(command[i++]);
		free(command);
		free(input);
	}
	else
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (status);
	}
}
return (0);
}
