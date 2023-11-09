#include "shell.h"

/**
 * fork_process - creates a child process
 *
 * Return: child process id
 */
pid_t fork_process(void)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
		exit(EXIT_FAILURE);
	return (child_pid);
}
/**
 * exec_execve - executes execve
 *
 * @command:parameter for execve
 *
 * Return: void
 */
void exec_execve(char **command)
{
	if (command[0] == NULL)
		exit(EXIT_SUCCESS);
	execve(command[0], command, environ);
	perror("./shell");
	_exit(127);
}
/**
 * exec_wait - executes wait command by parent
 *
 * @child_pid: child process id
 * @num_words: number of words in command
 * @status: exit status of child process
 *
 * Return: void
 */
void exec_wait(pid_t child_pid, int *status)
{
	waitpid(child_pid, status, 0);
}
