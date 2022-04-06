#include "main.h"

int simple_shell(shell_data_t *data)
{
	int ret;

	if (!isatty(STDIN_FILENO))
		read_prompt();
	else
	{
		do
		{
			_putstr("$ ");
		} while (read_prompt() != -1);
	}
	return (0);
}
