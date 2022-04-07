#include "main.h"

int		my_exit(struct shell_data_s *data, char **tokens)
{
	char	*param;
	int		i, nb;

	if (!tokens[1])
		data->exit = 0;
	else
	{
		nb = _atoi(tokens[1]);
		for (i = 0; tokens[1][i]; i++)
			if (tokens[1][i] < '0' || tokens[1][i] > '9')
			{
				_putstr_fd(get_filename(_getenv("SHELL", data->envp)), STDERR_FILENO);
				_putstr_fd(": ", 2);
				print_number_fd(data->nbcommands, STDERR_FILENO);
				_putstr_fd(": ", 2);
				_putstr_fd("exit", 2);
				_putstr_fd(": Illegal number: ", 2);
				_putstr_fd(tokens[1], 2);
				data->exit = -1;
				return (-1);
			}
	}
	return (1);
}
