#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 512

typedef struct shell_data_s
{
	char **envp;
} shell_data_t;

int read_prompt(void);
int simple_shell(shell_data_t *data);

char *_strtok(char *str, const char *delim);
char **_strsplit(char *str, const char *delim);
void free_tab(char ***tab);

int read_prompt(void);

size_t _strlen(char *str);
void _putstr(char *str);
char *_strpbrk(char *s, const char *accept);
char *_strndup(char *str, size_t n);

#endif
