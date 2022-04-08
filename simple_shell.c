#include "main.h"

/**
 * simple_shell - Default loop of simple_shell program
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
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
		do {
			_putstr("$ ");
		} while ((ret = read_prompt(data)) != -1);
		_putstr("\n");
	}
	return (0);
}
