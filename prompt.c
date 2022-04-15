#include "main.h"

/**
 * execute_command - Parses and tries to execute command line
 * @data: Pointer to data structure
 * Return: Always 0
 */
int		execute_command(shell_data_t *data)
{
	char	*command = NULL, *tmp;
	int		ret = 0;
	int		status = 1;
	alias_list_t	*alias;

	alias = get_alias(data->tokens[0], data->aliases);
	if (alias)
	{
		tmp = str_replace(data->tokens[0], alias->name, alias->replacement);
		if (!tmp)
			return (-1);
		_memdel((void *)&data->tokens[0]);
		data->tokens[0] = tmp;
	}
	ret = find_builtin(data);
	if (ret == -1)
	{
		command = find_command(data, data->tokens[0]);
		if (!command)
			return (-1);
		if (!command_exists(command))
		{
			print_error_not_found(data, command);
			data->return_status = 127;
		}
		else if (!fork() && execve(command, data->tokens, data->envp) == -1)
			print_error_not_found(data, command);
		else
		{
			wait(&status);
			data->return_status = status / 256;
		}
		_memdel((void *)&command);
	}
	if (ret == 1)
		return (-1);
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

	data->exit_err = 0;
	tmp = _strchr(data->buffer, '#');
	if (tmp)
		*tmp = '\0';
	data->commands = _strsplit(data->buffer, ";");
	_memdel((void *)&data->buffer);
	if (!data->commands)
		return (-1);
	while (data->commands[i])
	{
		data->tokens = _strsplit(data->commands[i], " \t\n");
		if (!data->tokens)
			return (-1);
		if (!data->tokens[0] || !_strlen(data->tokens[0]))
			return (0);
		if (execute_command(data) == -1)
			return (-1);
		if (data->exit_err)
			break;
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
		_memdel((void *)&data->buffer);
		return (-1);
	}
	if (data->buffer && _strlen(data->buffer) > 1)
	{
		if (add_history(data) || parse_execute_line(data))
		{
			_memdel((void *)&data->buffer);
			return (-1);
		}
	}
	_memdel((void *)&data->buffer);
	return (0);
}
