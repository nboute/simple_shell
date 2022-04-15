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
#include <signal.h>

#define BUF_SIZE 512

/**
 * struct alias_list_s - Linked list of aliass
 * @name: string
 * @replacement: string to replace with
 * @next: Pointer to next node
 */
typedef struct		alias_list_s
{
	char				*name;
	char				*replacement;
	struct alias_list_s	*next;
}					alias_list_t;


/**
 * struct builtin_s - Linked list of builtin functions
 * @name: Name of builtin command
 * @fct: Pointer to corresponding function
 * @next: Pointer to next node
 */
typedef struct		builtin_s
{
	char				*name;
	int					(*fct)(void *);
	struct builtin_s	*next;
}					builtin_t;
/**
 * struct history_s - linked list for history
 * @line: line of the command written by the user
 * @nb_line: permits to count the line of history
 * @next: pointer to next node
 */
typedef struct		history_s
{
	char				*line;
	int					nb_line;
	struct history_s	*next;
}					history_t;

/**
 * struct shell_data_s - General data structure
 * @exit_err: Tells program to exit in a specific case
 * @aliases: Alias list
 * @argv: Main arguments
 * @buffer: Buffer containing command line
 * @envp: Array of env variables strings
 * @paths: Array of PATH directories strings
 * @commands: Array of split commands
 * @tokens: Array of token strings for current shell command
 * @builtins_list: Linked list of builtin functions
 * @nbcommands: Number of commands entered in terminal
 * @return_status: Value of return when exiting program
 * @history: History of shell commands
 * @total_lines: Count of total_lines
 */
typedef struct				shell_data_s
{
	int				exit_err;
	alias_list_t	*aliases;
	char			**argv;
	char			*buffer;
	char			**envp;
	char			**paths;
	char			**commands;
	char			**tokens;
	builtin_t		*builtins_list;
	size_t			nbcommands;
	int				return_status;
	history_t		*history;
	int				total_lines;
}							shell_data_t;


int				simple_shell(shell_data_t *data);

int				is_in_str(char c, const char *str);
char			*_strtok(char *str, const char *delim);
char			**_strsplit(char *str, const char *delim);
void			free_tab(char ***tab);

int				read_prompt(shell_data_t *data);
char			*_getenv(const char *name, char **envp);
char			**_getenvptr(const char *name, char **envp);

int				get_path(shell_data_t *data);
char			*find_command(shell_data_t *data, char *command);
char			**copy_envp(char **envp);
int				find_builtin(shell_data_t *data);
int				init_builtins(shell_data_t *data);
char			*get_filename(char *path);
int				script_shell(shell_data_t *data);
int				parse_execute_line(shell_data_t *data);
int				add_history(shell_data_t *data);
alias_list_t	*get_alias(char *name, alias_list_t *list);
void			print_error_not_found(shell_data_t *data, char *command);
void			print_error_parameter(shell_data_t *data, char *command);
void			print_error_exit(shell_data_t *data, char *command);
void			free_data(shell_data_t *data);
int				command_exists(char *command);

size_t			_strlen(const char *str);
void			_putstr(char *str);
void			_putstr_fd(char *str, int fd);
char			*_strpbrk(char *s, const char *accept);
char			*_strndup(char *str, size_t n);
char			*_strdup(const char *str);
char			*_strcpy(char *dest, const char *src);
char			*_strjoin(char *s1, char *s2);
int				_strncmp(char *s1, char *s2, size_t n);
void			print_number_fd(int n, int fd);
int				_putchar_fd(char c, int fd);
int				_atoi(char *s);
int				_strcmp(char *s1, char *s2);
char			**copy_envp(char **envp);
void			_memdel(void **ptr);
void			*_memalloc(size_t size);
char			*_strchr(char *s, char c);
char			*_strstr(char *haystack, char *needle);
char			*str_replace(char *str, char *sub, char *replace);
char			*_strdup_ignseq(char *str, const char *delim);
char			*_strcat(char *dest, char *src);
void			*_bzero(void *dest, unsigned int n);

int				_setenv(void *data);
int				_setenv2(shell_data_t *data);
int				_unsetenv(void *data);
int				_printenv(void *data);
void			print_prompt(int a);
int				_help(void *data);
int				my_alias(void *data);
int				my_exit(void *data);
int				_history(void *data);

#endif /* __MAIN_H__ */
