#include "main.h"
/**
 * _setenv - add or change an environment
 * @addr: pointer to data structure
 * Return: 0 on success
 */
int _setenv(void *addr)
{
	shell_data_t	*data;
	char		**ptr, *oldptr, *new, *name = NULL, *value = NULL;

	data = (shell_data_t *)addr;
	if (!data->tokens || !data->tokens[0])
		return (-1);
	name = data->tokens[1];
	if (!name)
	{
		print_error_parameter(data, "setenv");
		return (0);
	}
	value = data->tokens[2];
	if (!value)
		return (0);
	new = _getenv(name, data->envp);
	if (new)
	{
		ptr = _getenvptr(name, data->envp);
		if (!ptr)
			return (-1);
		oldptr = *ptr;
		*ptr = malloc(sizeof(char) * strlen(name) + strlen(value) + 2);
		if (!*ptr)
			return (-1);
		_strcpy(*ptr, name);
		_strcat(*ptr, "=");
		_strcat(*ptr, value);
		if (oldptr)
			free(oldptr);
	}
	else
		_setenv2(data);

	return (0);
}
/**
 *_setenv2 - following of _setenv
 *@data: pointer to data structure
 * Return: 0 on success
 */
int _setenv2(shell_data_t *data)
{
	int		i, size = 0;
	char	**envp, *name = NULL, *value = NULL;

	name = data->tokens[1];
	value = data->tokens[2];
	for (i = 0; data->envp && data->envp[i] != NULL; i++)
		size++;
	envp = _memalloc(sizeof(char *) * (size + 2));
	if (envp == NULL)
		return (-1);
	for (i = 0; data->envp && data->envp[i] != NULL; i++)
		envp[i] = data->envp[i];
	_memdel((void *)&data->envp);
	envp[i] = malloc(sizeof(char) * strlen(name) + strlen(value) + 2);
	if (!envp[i])
	{
		free_tab(&envp);
		return (-1);
	}
	_strcpy(envp[i], name);
	_strcat(envp[i], "=");
	_strcat(envp[i], value);
	data->envp = envp;
	return (0);
}
