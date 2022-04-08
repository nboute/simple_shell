#include "main.h"
/**
 * read_prompt -  read_prompt
 * Return:
 */
int read_prompt(shell_data_t *data)
{
	char	*command;
	size_t	n = 0;
	int		ret = 0;

	data->nbcommands++;
	ret = getline(&data->buffer, &n, stdin);
	if (ret == -1)
	{
		if (data->buffer)
			_memdel((void*)&data->buffer);
		return (-1);
	}
	if (data->buffer)
	{
		if (_strlen(data->buffer) > 1)
		{
			data->tokens = _strsplit(data->buffer, " \n");
			if (!data->tokens)
				return (-1);
			ret = find_builtin(data);
			if (!ret)
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
					_memdel((void*)&command);
				}
			}
			free_tab(&data->tokens);
		}
		_memdel((void*)&data->buffer);
	}
	return (0);
}
