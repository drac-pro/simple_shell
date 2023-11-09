#include "shell.h"

/**
 * find_command - Function finds a file in the PATH variable
 * @filename: Name of the fie to find
 *
 * Return: the full file PATH if it exist. Otherwise NULL.
 */
char *find_command(const char *filename)
{
	char *path, *token, *path_copy;

	if (!filename)
		return (NULL);
	if (filename[0] == '/')
	{
		if (access(filename, F_OK) == 0)
		{
			return (_strdup(filename));

		}
		else
		{
			perror("./shell");
			return (NULL);
		}
	}
	path = getenv("PATH");
	path_copy = _strdup(path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char filepath[1024];

		snprintf(filepath, sizeof(filepath), "%s/%s", token, filename);

		if (access(filepath, F_OK) == 0)
		{
			free(path_copy);
			return (_strdup(filepath));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
