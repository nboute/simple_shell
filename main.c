#include "main.h"

/**
 * init_shell - Initialises shell_data_t structure
 * @data: Pointer to structure
 * @envp: Environment variables
 * Return: 0 on success, -1 on error
 */
int		init_shell(shell_data_t *data, char **envp)
{
	data->envp = copy_envp(envp);
	if (data->envp == NULL)
		return (-1);
	data->aliases = NULL;
	data->exit_err = 0;
	data->paths = NULL;
	data->builtins_list = NULL;
	data->tokens = NULL;
	data->buffer = NULL;
	data->commands = NULL;
	data->nbcommands = 0;
	data->return_status = 0;
	data->history = 0;
	data->total_lines = 0;
	if (init_builtins(data))
		return (-1);
	return (0);
}

/**
 * main - Start of simple_shell program
 * @ac: Number of arguments
 * @av: Array of arguments
 * @envp: Environment variables
 * Return: 0 on exit success, 2 on error
 */
int		main(int ac, char **av, char **envp)
{
	shell_data_t data;

	(void)ac;
	data.argv = av;
	if (init_shell(&data, envp) == -1)
		return (-1);
	simple_shell(&data);
	free_data(&data);
	return (data.return_status);
}
