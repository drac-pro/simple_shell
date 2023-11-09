#include "shell.h"

/**
 * _getline - gets user input and stores it in a string.
 *
 * Return: pointer to the string and NULL other wise
 */
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t char_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	char_read = getline(&line, &len, stdin);
	if (char_read == -1)
	{
		_free(&line);
		return (NULL);
	}
	if (char_read > 0 && line[char_read - 1] == '\n')
		line[char_read - 1] = '\0';
	return (line);
}
