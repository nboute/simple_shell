#include "main.h"
/**
 * read_prompt -  read_prompt
 * Return:
 */
int read_prompt(void)
{
	char *buf = NULL;
	size_t i, n = 0, id = 0;
	char **tabtokens;

	if (getline(&buf, &n, stdin) == -1)
		return (-1);
	if (buf)
	{
		if (_strlen(buf) > 1)
		{
			tabtokens = _strsplit(buf, " \n");
			if (!tabtokens)
				return (-1);
			id = fork();
			if (!id)
			{
				if (execve(tabtokens[0], tabtokens, NULL) == -1)
					perror("ERROR:");
			}
			wait(NULL);
			free_tab(&tabtokens);
		}
		free(buf);
		buf = NULL;
	}
}
