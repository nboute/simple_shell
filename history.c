#include "main.h"
/**
 *add_history - add commands written in history
 *@data: Pointer to data structure
 *Return: 0 on success
 */
int	add_history(shell_data_t *data)
{
	history_t *new_line, **head, *tmp;

	head = &data->history;

	new_line = malloc(sizeof(history_t));
	if (new_line == NULL)
		return (-1);

	new_line->line = _strdup(data->buffer);
	if (new_line->line == NULL)
	{
		free(new_line);
		return (-1);
	}
	new_line->next = 0;
	new_line->nb_line = data->total_lines;

	tmp = *head;
	if (*head != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_line;
	}
	else
		*head = new_line;
	data->total_lines += 1;
	return (0);
}
/**
 * _history - writes the history commands
 * @addr: Pointer to data structure
 * Return: 0 on success
 */
int _history(void *addr)
{
	shell_data_t	*data;
	history_t		*history;

	data = (shell_data_t *)addr;
	history = data->history;
	while (history)
	{
		if (history->nb_line >= data->total_lines - 1000)
		{
			print_number_fd(history->nb_line, STDOUT_FILENO);
			_putstr(" ");
			_putstr(history->line);
		}
		history = history->next;
	}
	return (0);
}
