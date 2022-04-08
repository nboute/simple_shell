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

/**
 * struct builtin_s - Linked list of builtin functions
 * @name: Name of builtin command
 * @fct: Pointer to corresponding function
 * @next: Pointer to next node
 */
typedef struct		builtin_s
{
	char				*name;
	int					(*fct)(struct shell_data_s *);
	struct builtin_s	*next;
}					builtin_t;

/**
 * struct shell_data_s - General data structure
 * @buffer: Buffer containing command line
 * @envp: Array of env variables strings
 * @paths: Array of PATH directories strings
 * @tokens: Array of token strings for current shell command
 * @builtins_list: Linked list of builtin functions
 * @nbcommands: Number of commands entered in terminal
 * @return_status: Value of return when exiting program
 */
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

int			is_in_str(char c, const char *str);
char		*_strtok(char *str, const char *delim);
char		**_strsplit(char *str, const char *delim);
void		free_tab(char ***tab);

int			read_prompt(shell_data_t *data);
char		*_getenv(const char *name, char **envp);
char		**_getenvptr(const char *name, char **envp);

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

int 		_setenv(shell_data_t *data);
int			_printenv(shell_data_t *data);
char		*_strcat(char *dest, char *src);
void		*_bzero(void *dest, unsigned int n);

#endif /* __MAIN_H__ */
