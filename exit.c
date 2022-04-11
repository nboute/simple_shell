#include "main.h"

/**
 * my_exit - Exits shell, Builtin exit function
 * @data: Pointer to data structure
 * Return: -1 if invalid parameter
 */
int		my_exit(shell_data_t *data)
{
	int		i, nb;

	if (!data->tokens[1])
		nb = 0;
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
			if (data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
			{
				print_error(data, "exit");
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
	_memdel((void *)&data->buffer);
}
