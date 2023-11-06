#include "shell.h"

/**
 * _strtok - splits a string into words and store them in an array of words
 *
 * @input: pointer to input string
 * @word_count: pointer to the number of words
 *
 * Return: pointer to an array of words
 */
char **_strtok(char *input, int *word_count)
{
	char **command = NULL, *ptr = input;
	const char *token, *delimiter = " ";
	int count = 0;

	token = strtok(ptr, delimiter);
	while (token != NULL)
	{
		command = realloc(command, (count + 1) * sizeof(char *));
		command[count] = _strdup(token);
		count++;
		token = strtok(NULL, delimiter);
	}
	command = realloc(command, (count + 1) * sizeof(char *));
	command[count] = NULL;
	*word_count = count;
	return (command);
}
