#include "main.h"

int		my_exit(struct shell_data_s *data)
{
	char	*param;
	int		i, nb;

	if (!data->tokens[1])
		nb = 0;
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
			if (data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
			{
				print_error(data, "exit");
				data->return_status = 2;
				return (-1);
			}
		nb = _atoi(data->tokens[1]);
	}
	free_data(data);
	exit(nb);
}

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
				_memdel((void*)&tmp->name);
			_memdel((void*)&tmp);
		}
	}
}

void	free_data(shell_data_t *data)
{
	free_tab(&data->envp);
	free_tab(&data->paths);
	free_tab(&data->tokens);
	free_builtins_list(&data->builtins_list);
	_memdel((void*)&data->buffer);
}
