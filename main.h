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
struct shell_data_s;

typedef struct		builtin_s
{
	char				*name;
	int					(*fct)(struct shell_data_s *);
	struct builtin_s	*next;
}					builtin_t;

typedef struct				shell_data_s
{
	char			*buffer;
	char			**envp;
	char			**paths;
	char			**tokens;
	builtin_t		*builtins_list;
	size_t			nbcommands;
	int				return_status;
}							shell_data_t;


int			simple_shell(shell_data_t *data);

char		*_strtok(char *str, const char *delim);
char		**_strsplit(char *str, const char *delim);
void		free_tab(char ***tab);

int			read_prompt(shell_data_t *data);
char		*_getenv(const char *name, char **envp);
int			get_path(shell_data_t *data);
char		*find_command(shell_data_t *data, char *command);
char		**copy_envp(char **envp);
int			find_builtin(shell_data_t *data);
int			init_builtins(shell_data_t *data);
char		*get_filename(char *path);

int			my_exit(struct shell_data_s *data);
void		print_error(shell_data_t *data, char *command);
void		free_data(shell_data_t *data);

size_t		_strlen(const char *str);
void		_putstr(char *str);
void		_putstr_fd(char *str, int fd);
char		*_strpbrk(char *s, const char *accept);
char		*_strndup(char *str, size_t n);
char		*_strdup(const char *str);
char		*_strcpy(char *dest, const char *src);
char		*_strjoin(char *s1, char *s2);
int			_strncmp(char *s1, char *s2, size_t n);
void		print_number_fd(int n, int fd);
int			_putchar_fd(char c, int fd);
int			_atoi(char *s);
int			_strcmp(char *s1, char *s2);
char		**copy_envp(char **envp);
void		_memdel(void **ptr);
void		*_memalloc(size_t size);

#endif /* __MAIN_H__ */
