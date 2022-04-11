#include "main.h"
/**
 *_history - prints the history of commands
 *@data: Pointer to data structure
 *Return:
 */
int	_history(shell_data_t *data)
{
	builtin_t *newhistory, *head, *tmp;
	char *str;
	int nb;
	str = data->commands;

	newhistory = (builtin_t *)malloc(sizeof(builtin_t));
	if (newhistory == NULL)
		return (NULL);

	newhistory->str = _strdup(str);
	if (newhistory->str == NULL)
	{
		free(newhistory);
		return (NULL);
	}
	newhistory->next = 0;

	tmp = *head;
	if (*head != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newhistory;
	}
	else
		*head = newhistory;

	_putstr(nb, );

	return (newhistory);
}
