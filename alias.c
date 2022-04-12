#include "main.h"

/**
 * get_alias - Get alias by name
 * @name: Name of alias to search
 * @list: Linked list of aliases
 * Return: Pointer to corresponding node
 */
alias_list_t	*get_alias(char *name, alias_list_t *list)
{
	while (list && _strcmp(list->name, name))
		list = list->next;
	return (list);
}

/**
 * print_alias - Prints alias name and value
 * @ptr: Pointer to alias list node
 */
void			print_alias(alias_list_t *ptr)
{
	_putstr(ptr->name);
	_putstr("='");
	_putstr(ptr->replacement);
	_putstr("'\n");
}

/**
 * add_alias - Adds alias to list
 * @list: Address of list's head
 * @alias: Name of alias
 * @replacement: Alias value
 * Return: New node
 */
alias_list_t	*add_alias(alias_list_t **list, char *alias, char *replacement)
{
	alias_list_t	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->name = alias;
	new->replacement = replacement;
	new->next = *list;
	*list = new;
	return (new);
}

/**
 * parse_alias - Read and execute alias
 *
 * @data: Pointer to data structure
 * Return: 0 on success
 */
int				parse_alias(shell_data_t *data)
{
	int				i, len;
	alias_list_t	*ptr;
	char			*tmp, *alias;

	for (i = 1; data->tokens[i]; i++)
	{
		tmp = _strchr(data->tokens[i], '=');
		len = tmp - data->tokens[i];
		if (!tmp || !len)
		{
			ptr = get_alias(data->tokens[i], data->aliases);
			if (!ptr)
			{
				data->return_status = 1;
				_putstr_fd("alias: ", STDERR_FILENO);
				_putstr_fd(data->tokens[i], STDERR_FILENO);
				_putstr_fd(" not found\n", STDERR_FILENO);
			}
			else
				print_alias(ptr);
		}
		else
		{
			alias = _strndup(data->tokens[i], tmp - data->tokens[i]);
			if (!alias)
				return (1);
			tmp = _strdup_ignseq(tmp + 1, "'");
			if (!tmp)
				free(alias);
			if (!tmp)
				return (1);
			if (!(add_alias(&data->aliases, alias, tmp)))
			{
				free(alias);
				free(tmp);
				return (1);
			}
		}
	}
	return (0);
}

/**
 * my_alias - Builtin alias function
 * @addr: Pointer to data structure
 * Return: -1 if invalid parameter
 */
int				my_alias(void *addr)
{
	shell_data_t	*data;
	alias_list_t	*ptr;

	data = (shell_data_t *)addr;
	if (!data->tokens[1])
	{
		ptr = data->aliases;
		while (ptr)
		{
			print_alias(ptr);
			ptr = ptr->next;
		}
		return (0);
	}
	else
		return (parse_alias(data));
}
