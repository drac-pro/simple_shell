#include "shell.h"

/**
 * main - simple unix command interpreter
 *
 * Return: 0 (success)
 */
int main(void)
{
while (1)
{
	int i = 0, num_words, status;
	char *line = NULL;
	size_t len = 0;
	ssize_t char_read;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	char_read = getline(&line, &len, stdin);
	if (char_read != -1)
	{
		char **command;
		pid_t child_pid;

		if (char_read > 0 && line[char_read - 1] == '\n')
			line[char_read - 1] = '\0';
		command = _strtok(line, &num_words), child_pid = fork();
		if (child_pid == -1)
			exit(EXIT_FAILURE);
		else if (child_pid == 0 && num_words == 1)
		{
			execve(command[0], command, environ);
			perror("./shell");
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (num_words > 1)
				perror("./shell");
		}
		while (command[i++] != NULL)
			free(command[i]);
		free(command);
		free(line);
	}
	else
		exit(EXIT_FAILURE);
}
return (0);
}
