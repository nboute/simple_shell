#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 512

typedef struct				shell_data_s
{
	char			**envp;
	char			**paths;
}							shell_data_t;


int simple_shell(shell_data_t *data);

char *_strtok(char *str, const char *delim);
char **_strsplit(char *str, const char *delim);
void free_tab(char ***tab);

int		read_prompt(shell_data_t *data);
char	*_getenv(const char *name, char **envp);
int		get_path(shell_data_t *data);
char		*find_command(shell_data_t *data, char *command);


size_t _strlen(char *str);
void _putstr(char *str);
char *_strpbrk(char *s, const char *accept);
char *_strndup(char *str, size_t n);
char	*_strdup(char *str);
char	*_strcpy(char *dest, char *src);
char	*_strjoin(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

#endif /* __MAIN_H__ */
