#include "main.h"
/**
 * _unsetenv - deletes the variable name from the environment
 * @data: pointer to data structure
 * Return: 0 on success the name is delete
 */
int _unsetenv(shell_data_t *data)
{
	char	*name, **env, **dup;
	int		i = 0, size = 0, j = 0;
	
	name = data->tokens[1];
	env = _getenvptr(name, data->envp);

	if (name == NULL || env == NULL)
	{
		/**
		* Write Error message here
		*/
		return (1);
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
	if (env[i])
		return (-1);

	return (0);
}
