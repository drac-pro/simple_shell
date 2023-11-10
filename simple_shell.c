#include "shell.h"

/**
 * main - simple unix command interpreter
 *
 * Return: 0 (success)
 */
int main(void)
{
	int status = 0;

while (1)
{
	int num_words;
	char *input = _getline();

	if (input)
	{
		char **command;
		pid_t child_pid;

		command = input_token(input, &num_words);
		_free(&input);
		command[0] = find_command(command[0]);
		if (!command[0])
		{
			free_command(command);
			write(2, ".shell: No such file or directory\n", 34);
			continue;
		}
		child_pid = fork_process();
		if (child_pid == 0)
			exec_execve(command);
		else
			exec_wait(child_pid, &status);
		free_command(command);
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
