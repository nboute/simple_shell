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

int prompt(void);
void simple_shell(shell_data_t *data);

size_t _strlen(char *str);
void _putstr(char *str);

#endif
