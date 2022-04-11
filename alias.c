#include "main.h"

alias_list_t	*get_alias(char *name, alias_list_t *list)
{
	while (list && _strcmp(list->alias, name))
		list = list->next;
	return (list)
}

void			print_alias(alias_list_t *ptr)
{
	_putstr(ptr->alias);
	_putstr("'=");
	_putstr(ptr->replacement);
	_putstr("'\n");
}

/**
 * my_alias - aliass shell, Builtin alias function
 * @data: Pointer to data structure
 * Return: -1 if invalid parameter
 */
int				my_alias(shell_data_t *data)
{
	int				i, nb;
	alias_list_t	*ptr;
	char			*name, *tmp;

	if (!data->tokens[1])
	{
		ptr = data->aliases;
		while (ptr)
		{
			print_alias(ptr);
			ptr = ptr->next;
		}
	}
	else
	{
		for (i = i; data->tokens[i]; i++)
		{
			tmp = _strchr(data->tokens[i], '=');
			if (!tmp)
			{
				ptr = get_alias(data->tokens[i], data->aliases);
				if (!ptr)
					data->return_status = 1;
				else
					print_alias(ptr);
			}
			else
			{
				tmp = _strdup_ignseq(tmp + 1, "'");
				/**
				 * add_alias function here
				 *
				 */

			}
		}
		for (i = 0; data->tokens[1][i]; i++)
			if (data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
			{
				print_error(data, "alias");
				if (!isatty(STDIN_FILENO))
					exit(2);
				data->exit_err = 1;
				data->return_status = 2;
				return (0);
			}
		nb = _atoi(data->tokens[1]);
	}
}

