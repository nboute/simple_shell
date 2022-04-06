#include "main.h"
/**
 * _strchrlen - calculate the length until a given character
 * @str: the string
 * @c: the given character
 * Return: -1 if the character is not find
 */
int _strchrlen(char *str, char c)
{
	int len;

	for (len = 0; str[len] && c; len++)
	{
		if (str[len] == c)
			return (len);
	}
	return (-1);
}
/**
 * read_line - read the file and copy a string into a buffer
 * line
 * n
 * stream
 * return:
 */
char *read_line(char **line, size_t *n, FILE *stream)
{
	char buffer[BUF_SIZE + 1];
	int ret, len;

	ret = read(STDIN_FILENO, buffer, BUF_SIZE);
	buffer[ret] = NULL;
	len = _strchrlen(buffer, '\n');
	if (len == -1)
	{
		// Ajouter buffer a la ligne et continuer a lire
	}
	else
	{
		if (*line)
		{
			// Rejoindre ancien buffer avec nouveau
		}
		else
		{
			// vider line
			// *line = NULL;
			*n = len;
			return (buffer);
		}
		// Recuperer partie du buffer avec la ligne en question
	}
}
/**
 * check_line_buffer - check if a line is present in the buffer
 * @buffer:
 * Return:
 */
char *check_line_buffer(char *buffer)
{
	int len;

	len = _strchrlen(buffer, '\n');
	if (len != -1)
	{
		// Ressortir ligne du buffer en retour de getline
	}
	else
		return (NULL);
}

/**
 * _getline - Reads next line from file stream
 * @buf: the buffer
 * @n: the size of the buffer
 * @stream: handle the file
 * Return: -1 on failure, on success the number of characters read without \0
 */

int _getline(char **buf, size_t *n, FILE *stream)
{
	static char *line = NULL;

	if (!stream || !buf || !n)
		return (-1);
	if (line)
		check_line_buffer(line);
	read_line(&line, &n, stream);
}
