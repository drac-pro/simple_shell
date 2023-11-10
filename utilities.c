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
 * *_strncat - This function appends the src string to the dest string
 * @dest: first pointer that points to char.
 * @src: second pointer that points to char.
 * @n: the number of bytes.
 *
 * Return: ptr.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	char *ptr = dest;
	int dest_len = 0;

	while (*dest != '\0')
		dest++;

	for (i = 0; src[i] != '\0' && n > 0; i++, n--)
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
