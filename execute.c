#include "shell.h"

void execute(char **command)
{
	pid_t child;
	int status;

	command[0] = find_command(command[0]);
	if (!command[0])
	{
		write(2, "./shell: no such file or directory\n", 35);
		return;
	}
	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execve(command[0], command, environ);
		perror("./shell");
		_exit(127);
	}
	else
	{
	do {
		waitpid(child, &status, WUNTRACED);
	} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
}

int exec_builtin(char **command)
{
	int i;
	built_c commands[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	for (i = 0; commands[i].cmd != NULL; i++)
	{
		if (strcmp(commands[i].cmd, command[0]) == 0)
			commands[i].f(command);
	}
	if (commands[i].cmd == NULL)
		return (1);
	return (0);
}
