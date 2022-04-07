#include "main.h"

char	*_getenv(const char *name, char **envp)
{
	size_t	i, len;

	for (len = 0; name[len]; len++)
		;
	i = 0;
	while (envp[i])
	{
		if (!_strncmp(envp[i], (char*)name, len))
		{
			if (envp[i][len] == '=')
				return (envp[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
