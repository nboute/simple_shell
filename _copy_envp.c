#include "main.h"

/**
 * copy_envp - Duplicates double entry array
 * @envp: Array to duplicate
 * Return: Newly created array
 */
char **copy_envp(char **envp)
{
	char	**newenvp;
	int		i;

	for (i = 0; envp[i] != NULL; i++)
		;
	newenvp = _memalloc((i + 1) * sizeof(char *));
	if (newenvp == NULL)
		return (NULL);

	for (i = 0; envp[i] != NULL; i++)
	{
		newenvp[i] = strdup(envp[i]);
		if (!newenvp[i])
		{
			while (--i >= 0)
				_memdel((void *)&newenvp[i]);
			_memdel((void *)&newenvp);
			return (NULL);
		}
	}
	newenvp[i] = NULL;
	return (newenvp);
}
