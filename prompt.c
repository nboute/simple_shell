#include "main.h"
/**
 * read_prompt -  read_prompt
 * Return:
 */
int read_prompt(shell_data_t *data)
{
	char *buf = NULL, *command;
	size_t n = 0, id = 0;
	int ret = 0;
	char **tabtokens;

	ret = getline(&buf, &n, stdin);
	if (ret == -1)
	{
		if (buf)
			free(buf);
		return (-1);
	}
	if (buf)
	{
		if (_strlen(buf) > 1)
		{
			tabtokens = _strsplit(buf, " \n");
			if (!tabtokens)
				return (-1);
			command = find_command(data, tabtokens[0]);
			if (command)
			{
				id = fork();
				if (!id)
				{
					if (execve(command, tabtokens, data->envp) == -1)
					{
						perror("ERROR:");
					}
				}
				wait(NULL);
			}
			free_tab(&tabtokens);
		}
		free(buf);
		buf = NULL;
	}
	return (0);
}
