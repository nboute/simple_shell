#include "main.h"

/**
 * execute_command - Parses and tries to execute command line
 * @data: Pointer to data structure
 * Return: Always 0
 */
int		execute_command(shell_data_t *data)
{
	char	*command;
	int		ret = 0;

	ret = find_builtin(data);
	if (ret == -1)
	{
		command = find_command(data, data->tokens[0]);
		if (command)
		{
			if (!fork())
				if (execve(command, data->tokens, data->envp) == -1)
				{
					perror("ERROR:");
					exit(2);
				}
			wait(NULL);
			_memdel((void *)&command);
		}
	}
	return (0);
}

/**
 * parse_execute_line - Parses, formats and executes command line
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int	parse_execute_line(shell_data_t *data)
{
	char	*tmp;
	int		i = 0;

	tmp = _strchr(data->buffer, '#');
	if (tmp)
		*tmp = '\0';
	data->commands = _strsplit(data->buffer, ";");
	_memdel((void *)&data->buffer);
	if (!data->commands)
		return (-1);
	while (data->commands[i])
	{
		data->tokens = _strsplit(data->commands[i], " \n");
		if (!data->tokens)
			return (-1);
		if (execute_command(data))
			return (-1);
		free_tab(&data->tokens);
		i++;
	}
	free_tab(&data->commands);
	return (0);
}

/**
 * read_prompt - Gets next line on prompt and formats it for execution
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int read_prompt(shell_data_t *data)
{
	size_t	n = 0;
	int		ret;

	data->nbcommands++;
	ret = getline(&data->buffer, &n, stdin);
	if (ret == -1)
	{
		if (data->buffer)
			_memdel((void *)&data->buffer);
		return (-1);
	}
	if (data->buffer && _strlen(data->buffer) > 1)
	{
		if (parse_execute_line(data))
			return (-1);
	}
	return (0);
}
