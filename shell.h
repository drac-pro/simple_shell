#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

pid_t fork_process(void);
void exec_execve(char **command);
void exec_wait(pid_t child_pid, int num_words, int *status);

char **input_token(char *input, int *word_count);
char *_strdup(const char *str);
char *_getline(void);

#endif /* SHELL_H */
