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
	if (ret)
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
	free_tab(&data->tokens);
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
	if (data->buffer)
	{
		if (_strlen(data->buffer) > 1)
		{
			// parse_line(data);
			data->tokens = _strsplit(data->buffer, " \n");
			if (!data->tokens)
				return (-1);
			if (execute_command(data))
				return (-1);
		}
	}
	_memdel((void *)&data->buffer);
	return (0);
}
