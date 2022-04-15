#include "main.h"
/**
 * _unsetenv - deletes the variable name from the environment
 * @addr: pointer to data structure
 * Return: 0 on success the name is delete
 */
int _unsetenv(void *addr)
{
	shell_data_t	*data;
	char	*name, **env, **dup;
	int		i = 0, size = 0, j = 0;

	data = (shell_data_t *)addr;
	name = data->tokens[1];
	if (name == NULL)
	{
		print_error_parameter(data, "unsetenv");
		return (0);
	}
	env = _getenvptr(name, data->envp);
	if (env == NULL)
	{
		print_error_parameter(data, "unsetenv");
		return (0);
	}
	for (size = 0; data->envp[size] != NULL; size++)
		;
	dup = _memalloc(sizeof(char *) * (size));
	for (i = 0; data->envp[i] != NULL; i++)
	{
		if (data->envp[i] != *env)
		{
			dup[j] = data->envp[i];
			j++;
		}
	}
	free(*env);
	free(data->envp);
	data->envp = dup;
	return (0);
}
