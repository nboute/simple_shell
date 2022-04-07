#include "main.h"
char **copy_envp(char **envp)
{
	char	**newenvp;
	int		i;

	for (i = 0; envp[i] != NULL; i++)
		;
	newenvp = malloc((i + 1) * sizeof(char*));
	if (newenvp == NULL)
		return (NULL);

	for (i = 0; envp[i] != NULL; i++)
	{
		newenvp[i] = strdup(envp[i]);
		if (!newenvp[i])
		{
			while (--i >= 0)
				free(newenvp[i]);
			free(newenvp);
			return (NULL);
		}
	}
	newenvp[i] = NULL;
	return (newenvp);
}
