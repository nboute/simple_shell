#include "main.h"

/**
 * add_builtin - Add a builtin to builtins linked list
 * Builtins are functions for the simple_shell that are defined in the program
 * itself
 * @data: Pointer to data structure
 * @name: String, Name of builtin
 * @fct: Builtin function pointer
 * Return: Pointer to new linked list node
 */
builtin_t	*add_builtin(shell_data_t *data, const char *name,
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

/**
 * init_builtins - Initializes builtins linked list
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int		init_builtins(shell_data_t *data)
{
	if (!add_builtin(data, "exit", my_exit))
		return (-1);
	if (!add_builtin(data, "setenv", _setenv))
		return (-1);
	if (!add_builtin(data, "env", _printenv))
		return (-1);
}

/**
 * find_builtin - Checks if command is a builtin
 * @data: Pointer to data structure
 * Return: 0 if none was found
 */
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
