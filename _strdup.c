#include "shell.h"

/**
 * _strdup - copies a string to a newly allocated space in memory
 *
 * @str: pointer to string to be copied
 *
 * Return: a pointer to the allocated space in memory or NULL if string is NULL
 */
char *_strdup(const char *str)
{
	int i, size = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		size++;

	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = str[i];
	ptr[size] = '\0';

	return (ptr);
}
