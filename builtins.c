#include "main.h"

struct builtin_s	*add_builtin(shell_data_t *data, const char *name,
					int (*fct)(struct shell_data_s *, char **))
{
	builtin_t	*new;

	new = malloc(sizeof(*new));
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

int		find_builtin(shell_data_t *data, char **tokens)
{
	builtin_t	*ptr;

	if (!tokens || !tokens[0])
		return (0);
	ptr = data->builtins_list;
	while (ptr && ptr->name)
	{
		if (!_strcmp(ptr->name, tokens[0]))
			return (ptr->fct(data, tokens));
		ptr = ptr->next;
	}
	return (0);
}
