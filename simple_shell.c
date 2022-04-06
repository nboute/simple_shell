#include "main.h"

int simple_shell(shell_data_t *data)
{

	if (!isatty(STDIN_FILENO))
		read_prompt(data);
	else
	{
		do
		{
			_putstr("$ ");
		} while (read_prompt(data) != -1);
	}
	return (0);
}
