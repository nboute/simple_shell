#include "main.h"
/**
 * read_prompt -  read_prompt
 * Return:
 */
int read_prompt(shell_data_t *data)
{
	char *buf = NULL;
	size_t i, n = 0, id = 0, ret = 0;
	char **tabtokens;

	ret = getline(&buf, &n, stdin);
	if (ret == -1)
		return (-1);
	if (buf)
	{
		if (_strlen(buf) > 1)
		{
			tabtokens = _strsplit(buf, " \n");
			if (!tabtokens)
				return (-1);
			// test if command exists here
			id = fork();
			if (!id)
			{
				if (execve(tabtokens[0], tabtokens, data->envp) == -1)
				{
					perror("ERROR:");
				}
			}
			wait(NULL);
			free_tab(&tabtokens);
		}
		free(buf);
		buf = NULL;
	}
	return (0);
}
