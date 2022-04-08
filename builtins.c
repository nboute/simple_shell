#include "main.h"

struct builtin_s	*add_builtin(shell_data_t *data, const char *name,
					int (*fct)(struct shell_data_s *))
{
	builtin_t	*new;

	new = _memalloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->name = _strdup(name);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}
	new->fct = fct;
	new->next = data->builtins_list;
	data->builtins_list = new;
	return (new);
}

int		init_builtins(shell_data_t *data)
{
	if (!add_builtin(data, "exit", my_exit))
		return (-1);
}

int		find_builtin(shell_data_t *data)
{
	builtin_t	*ptr;

	if (!data->tokens || !data->tokens[0])
		return (0);
	ptr = data->builtins_list;
	while (ptr && ptr->name)
	{
		if (!_strcmp(ptr->name, data->tokens[0]))
			return (ptr->fct(data));
		ptr = ptr->next;
	}
	return (0);
}
