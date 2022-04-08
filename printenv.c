#include "main.h"
/**
 * _printenv - print the environment
 *
 */
int _printenv(shell_data_t *data)
{
	int	i;

	for (i = 0; data->envp[i] != NULL; i++)
	{
		_putstr(data->envp[i]);
		_putstr("\n");
	}
	return (0);
}
