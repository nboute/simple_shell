#include "main.h"

int		init_shell(shell_data_t *data, char **envp)
{
	data->envp = copy_envp(envp);
	if (data->envp == NULL)
		return (-1);
	data->paths = NULL;
	data->builtins_list = NULL;
	data->nbcommands = 0;
	data->exit = -1;
	if (!init_builtins(data))
		return (-1);
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	shell_data_t data;

	(void)ac;
	(void)av;
	if (init_shell(&data, envp) == -1)
		return (-1);
	simple_shell(&data);
	return (data.exit);
}
