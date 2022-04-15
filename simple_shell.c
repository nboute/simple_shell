#include "main.h"

/**
 * read_file - Gets next line in file and formats it for execution
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int		read_file(shell_data_t *data)
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
	if (data->buffer && _strlen(data->buffer) > 1)
	{
		if (parse_execute_line(data))
			return (-1);
	}
	return (0);
}

/**
 * simple_shell - Default loop of simple_shell program
 * @data: Pointer to data structure
 * Return: 0 on success, -1 on error
 */
int simple_shell(shell_data_t *data)
{
	int	ret;

	signal(SIGINT, print_prompt);
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

/**
 * print_prompt - Prints prompt sign
 * @a: Unused parameter
 */
void print_prompt(int a)
{
	(void)a;
	_putstr("\n$ ");
}
