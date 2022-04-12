#include "main.h"
/**
 * _printenv - print the environment
 * @addr: Pointer to data structure
 * Return: Always 0
 */
int _printenv(void *addr)
{
	int	i;
	shell_data_t	*data;

	data = (shell_data_t *)addr;
	for (i = 0; data->envp && data->envp[i] != NULL; i++)
	{
		_putstr(data->envp[i]);
		_putstr("\n");
	}
	return (0);
}
