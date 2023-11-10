#include "shell.h"

/**
 * find_command - Function finds a file in the PATH variable
 * @filename: Name of the fie to find
 *
 * Return: the full file PATH if it exist. Otherwise NULL.
 */
char *find_command(char *filename)
{
	char *path, *token, *filepath, *path_copy;

	if (!filename)
		return (NULL);
	if (filename[0] == '/')
	{
		if (access(filename, F_OK) == 0)
			return (_strdup(filename));
		else
		{
			perror("./shell");
			return (NULL);
		}
	}
	path = getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		filepath = malloc(_strlen(token) + _strlen(filename) + 2);
		if(!filepath)
		{
			free(path);
			return(NULL);
		}
		_strcpy(filepath, token);
		_strcat(filepath, "/");
		_strcat(filepath, filename);

		if (access(filepath, F_OK) == 0)
		{
			free(path_copy);
			return (filepath);
		}
		free(filepath);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
