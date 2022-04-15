#include "main.h"
/**
 * get_path - Splits PATH into array of path directories
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int		get_path(shell_data_t *data)
{

	int		i = 0;
	char	*path, *tmp;

	if (data->paths)
		free_tab(&data->paths);
	if (!data->envp)
		return (0);
	tmp = _getenv("PATH", data->envp);
	if (!tmp)
		return (0);
	path = _strdup(tmp);
	if (!path)
		return (-1);
	data->paths = _strsplit(path, ":");
	_memdel((void *)&path);
	if (!data->paths)
		return (-1);
	for (i = 0; data->paths[i] != NULL; i++)
	{
		tmp = data->paths[i];
		data->paths[i] = _strjoin(data->paths[i], "/");
		_memdel((void *)&tmp);
		if (!data->paths[i])
		{
			while (--i >= 0)
				_memdel((void *)&data->paths[i]);
			_memdel((void *)&data->paths);
			return (-1);
		}
	}
	return (0);
}

/**
 * get_filename - Gets filename from a path
 * @path: Path string
 * Return: Pointer to where filename starts
 */
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

/**
 * command_exists - Test if a command corresponds to an executable file
 *
 * @command: Command string
 * Return: 1 if valid, 0 if not
 */
int			command_exists(char *command)
{
	struct stat	filestats;

	if (stat(command, &filestats) >= 0)
	{
		if (filestats.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			return (1);
	}
	return (0);
}

/**
 * find_command - Checks if command exists in PATH directories
 * @data: Pointer to data structure
 * @command: Command string
 * Return: Full path of existing command or NULL if it can't be found/executed
 */
char		*find_command(shell_data_t *data, char *command)
{
	int			i;
	char		*filepath;

	get_path(data);
	if (*command != '/' && *command != '.')
	{
		for (i = 0; data->paths && data->paths[i]; i++)
		{
			filepath = _strjoin(data->paths[i], command);
			if (!filepath)
				return (NULL);
			if (command_exists(filepath))
				return (filepath);
			_memdel((void *)&filepath);
		}
	}
	return (_strdup(command));
}
