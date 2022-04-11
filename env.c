#include "main.h"

/**
 * _getenv - Get a specific environment variable value
 * @name: Name of variable to search for
 * @envp: Array of environment variables
 * Return: String with selected variable, or NULL if it wasn't found
 */
char	*_getenv(const char *name, char **envp)
{
	size_t	i, len;

	for (len = 0; name[len]; len++)
		;
	i = 0;
	while (envp && envp[i])
	{
		if (!_strncmp(envp[i], (char *)name, len))
		{
			if (envp[i][len] == '=')
				return (envp[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * _getenvptr - Get a specific environment variable address
 * @name: Name of variable to search for
 * @envp: Array of environment variables
 * Return: String with selected variable, or NULL if it wasn't found
 */
char	**_getenvptr(const char *name, char **envp)
{
	size_t	i, len;

	for (len = 0; name[len]; len++)
		;
	i = 0;
	while (envp && envp[i])
	{
		if (!_strncmp(envp[i], (char *)name, len))
		{
			if (envp[i][len] == '=')
				return (envp + i);
		}
		i++;
	}
	return (NULL);
}
