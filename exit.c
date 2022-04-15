#include "main.h"

/**
 * my_exit - Exits shell, Builtin exit function
 * @addr: Pointer to data structure
 * Return: -1 if invalid parameter
 */
int		my_exit(void *addr)
{
	int		i, nb;
	shell_data_t	*data;

	data = (shell_data_t *)addr;
	if (!data->tokens[1])
		nb = data->return_status;
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
			if (data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
			{
				print_error_exit(data, "exit");
				if (!isatty(STDIN_FILENO))
					exit(2);
				data->exit_err = 1;
				data->return_status = 2;
				return (0);
			}
		nb = _atoi(data->tokens[1]);
	}
	free_data(data);
	exit(nb);
}

/**
 * free_builtins_list - Frees linked list
 * @list: Adress of head of linked list
 */
void	free_builtins_list(builtin_t **list)
{
	builtin_t	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list);
			*list = (*list)->next;
			if (tmp->name)
				_memdel((void *)&tmp->name);
			_memdel((void *)&tmp);
		}
	}
}
/**
 * free_history - Frees history
 * @history: History linked list
 */
void	free_history(history_t **history)
{
	history_t	*tmp;

	if (history)
	{
		while (*history)
		{
			tmp = (*history);
			*history = (*history)->next;
			if (tmp->line)
				_memdel((void *)&tmp->line);
			_memdel((void *)&tmp);
		}
	}
}
/**
 * free_aliases - Frees aliases
 * @aliases: aliases linked list
 */
void	free_aliases(alias_list_t **aliases)
{
	alias_list_t	*tmp;

	if (aliases)
	{
		while (*aliases)
		{
			tmp = (*aliases);
			*aliases = (*aliases)->next;
			_memdel((void *)&tmp->name);
			_memdel((void *)&tmp->replacement);
			_memdel((void *)&tmp);
		}
	}
}
/**
 * free_data - Frees variables in shell_data_t structure
 * @data: Pointer to data sturcture
 */
void	free_data(shell_data_t *data)
{
	free_tab(&data->envp);
	free_tab(&data->paths);
	free_tab(&data->tokens);
	free_builtins_list(&data->builtins_list);
	free_tab(&data->commands);
	free_history(&data->history);
	free_aliases(&data->aliases);
	_memdel((void *)&data->buffer);
}
