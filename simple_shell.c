#include "shell.h"

/**
 * main - simple unix command interpreter
 *
 * Return: 0 (success)
 */
int main(void)
{
	int status = 0;
	char *input;

while ((input = _getline()) != NULL)
{
	int num_words, exec_flag;
	char **command;

	command = input_token(input, &num_words);
	if (command[0] == NULL)
	{
		_free(&input);
		free_command(command);
		continue;
	}
	_free(&input);
	exec_flag = exec_builtin(command);
	if (exec_flag == 1)
		execute(command);
	free_command(command);
}
if (isatty(STDIN_FILENO) && !input)
	write(STDOUT_FILENO, "\n", 1);
_free(&input);
return (status);
}
