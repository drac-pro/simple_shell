#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char **_strtok(char *input, int *word_count);
char *_strdup(char *str);


#endif /* SHELL_H */
