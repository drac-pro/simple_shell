#include "shell.h"

/**
 * input_token - splits a string into words and store them in an array of words
 *
 * @input: pointer to input string
 * @word_count: pointer to the number of words
 *
 * Return: pointer to an array of words
 */
char **input_token(char *input, int *word_count)
{
	char **command = NULL, *ptr = _strdup(input), *token;
	const char *delimiter = " \t\n";
	int i = 0, size = 0;

	token = strtok(ptr, delimiter);
	while (token)
		size++, token = strtok(NULL, delimiter);
	command = malloc(sizeof(char *) * (size + 1));
	token = strtok(input, delimiter);
	while (token)
	{
		command[i] = _strdup(token), i++;
		token = strtok(NULL, delimiter);
	}
	command[size] = NULL;
	*word_count = size;
	_free(&ptr);
	return (command);
}
