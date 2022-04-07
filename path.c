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

char		*get_filename(char *path)
{
	int		i = 0, state_filename = 0, count = 0;

	while (path[i])
	{
		if (path[i] != '/' && state_filename == 0)
		{
			state_filename = 1;
			count++;
		}
		if (path[i] == '/')
			state_filename = 0;
		i++;
	}
	i = 0;
	state_filename = 0;
	while (count > 0)
	{
		if (path[i] != '/' && state_filename == 0)
		{
			state_filename = 1;
			count--;
		}
		if (path[i] == '/')
			state_filename = 0;
		i++;
	}
	return (path + i);
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
		free(filepath);
	}
	_putstr_fd(get_filename(_getenv("SHELL", data->envp)), STDERR_FILENO);
	_putstr_fd(": ", 2);
	print_number_fd(data->nbcommands, STDERR_FILENO);
	_putstr_fd(": ", 2);
	_putstr_fd(command, 2);
	_putstr_fd(": not found\n", 2);
	return (NULL);
}
