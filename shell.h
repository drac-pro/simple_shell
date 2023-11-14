#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct builtin_commands
{
	char *cmd;
	void (*f)(char **command);
} built_c;
extern char **environ;

/**executes*/
void execute(char **command);
int exec_builtin(char **command);

char **input_token(char *input, int *word_count);
char *_strdup(const char *str);
char *_getline(void);
char *find_command(char *filename);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/**builtin commands*/
void exit_shell(char **command);
void print_env(char **command);

/*frees*/
void _free(char **str);
void free_command(char **command);

#endif /* SHELL_H */
