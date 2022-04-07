#include "main.h"
/** get_path -
*
*
*/
int		get_path(shell_data_t *data)
{

	int		i = 0;
	char	*path, *tmp;

	path = _strdup(_getenv("PATH", data->envp));
	if (!path)
		return (-1);
	data->paths = _strsplit(path, ":");
	free(path);
	if (!data->paths)
		return (-1);
	for (i = 0; data->paths[i] != NULL; i++)
	{
		tmp = data->paths[i];
		data->paths[i] = _strjoin(data->paths[i], "/");
		free(tmp);
		if (!data->paths[i])
		{
			while (--i >= 0)
				free(data->paths[i]);
			free(data->paths);
			return (-1);
		}
	}
	return (0);
}

char		*find_command(shell_data_t *data, char *command)
{
	int			i;
	struct stat	filestats;
	char		*filepath;

	for (i = 0; data->paths[i]; i++)
	{
		filepath = _strjoin(data->paths[i], command);
		if (!filepath)
			return (NULL);
		if (stat(filepath, &filestats) >= 0)
		{
			if (filestats.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
				return (filepath);
		}
	}
	return (NULL);
}
