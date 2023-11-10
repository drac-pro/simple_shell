#include "shell.h"

/**
 * *_strcpy - function that copies the string pointed to by src
 * @dest: pointer to the buffer
 * @src: pointer to the string
 *
 * Return: ptr.
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest = *src;

		dest++;
		src++;
	}

	*dest = '\0';

	return (ptr);
}
/**
 * *_strcat - This function appends the src string to the dest string
 * @dest: first pointer that points to char.
 * @src: second pointer that points to char.
 *
 * Return: ptr.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	char *ptr = dest;
	int dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len++] = src[i];
	dest[dest_len] = '\0';
	return (ptr);
}
/**
 * _strlen - This function returns the length of a string.
 * @s: The string to be counted.
 *
 * Return: Returns i.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
	}

	return (i);
}
/**
 * _strcmp - Function compares 2 strings.
 * @s1 : Points to the first string.
 * @s2 : Points to the second string.
 *
 * Return: s1[i] - s2[i].
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != 0))
		i++;

	return ((int)s1[i] - (int)s2[i]);
}
