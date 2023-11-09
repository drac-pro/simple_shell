#include "shell.h"

/**
 * _free - free a pointer and set it to NULL
 *
 * @str: adress of the pointer
 *
 * Return: void;
 */
void _free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
/**
  * free_command - free an array of strings
  *
  * @command: array of strings
  *
  * Return: void
  */
void free_command(char **command)
{
	char **temp = command;

	if (command)
	{
		while (*command)
			free(*command++);
		free(temp);
	}
}
