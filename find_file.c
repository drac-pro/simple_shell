#include "shell.h"

/**
 * find_command - Function finds a file in the PATH variable
 * @filename: Name of the fie to find
 *
 * Return: the full file PATH if it exist. Otherwise NULL.
 */
char *find_command(const char *filename)
{
	char *path, *token, *path_copy, *filepath;

	if (!filename)
		return (NULL);
	if (filename[0] == '/')
	{
		if (access(filename, F_OK) == 0)
			return (filename);
		else
		{
			perror("./shell");
			return (NULL);
		}
	}
	path = getenv("PATH");
	token = strtok(path, ":");
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
			free(path);
			return (filepath);
		}
		free(filepath);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
