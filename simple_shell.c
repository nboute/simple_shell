#include "main.h"

int simple_shell(shell_data_t *data)
{
	int	ret;

	if (get_path(data) == -1)
		return (-1);
	if (!isatty(STDIN_FILENO))
	{
		while (read_prompt(data) != -1)
			;
	}
	else
	{
		do
		{
			if (data->exit == -1)
				_putstr("$ ");
		} while (data->exit == -1 && (ret = read_prompt(data)) != -1);
		if (data->exit == -1)
			_putstr("\n");
	}
	return (0);
}
