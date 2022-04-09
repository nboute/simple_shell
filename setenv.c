#include "main.h"
/**
 * _setenv - add or change an environment
 * @data: pointer to data structure
 * Return: 0 on success
 */
int _setenv(shell_data_t *data)
{
	int				i, size = 0;
	char			**envp, **ptr, *oldptr, *new, *name, *value;

	name = data->tokens[1];
	value = data->tokens[2];
	if (!name || !value)
		return (0);
	new = _getenv(name, data->envp);
	if (new)
	{
		ptr = _getenvptr(name, data->envp);
		if (!ptr)
			return (-1);
		oldptr = *ptr;
		*ptr = malloc(sizeof(char) * strlen(name) + strlen(value) + 2);
		_strcpy(*ptr, name);
		_strcat(*ptr, "=");
		_strcat(*ptr, value);
		if (!*ptr)
			return (-1);
		if (oldptr)
			free(oldptr);
	}
	else
	{
		for (i = 0; data->envp[i] != NULL; i++)
			size++;
		envp = _memalloc(sizeof(char *) * (size + 2));
		if (envp == NULL)
			return (-1);
		for (i = 0; data->envp[i] != NULL; i++)
			envp[i] = data->envp[i];
		_memdel((void *)&data->envp);
		envp[i] = malloc(sizeof(char) * strlen(name) + strlen(value) + 2);
		_strcpy(envp[i], name);
		_strcat(envp[i], "=");
		_strcat(envp[i], value);
		data->envp = envp;
	}
	return (0);
}
