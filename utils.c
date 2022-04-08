#include "main.h"
/**
 * _strlen - Calculates length of a string
 * @str: String to mesure
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
/**
 * _putstr - print a string
 * @str: the string
 * Return: None
 */
void _putstr(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * _putstr_fd - print a string on given file descriptor
 * @str: the string
 * @fd: fd to print string to
 * Return: None
 */
void _putstr_fd(char *str, int fd)
{
	write(fd, str, _strlen(str));
}
/**
 * _strpbrk - Searches for any of the bytes of a substring in another string
 * @s: String to search into
 * @accept: Set of bytes to search
 * Return: Pointer to first match
 */
char *_strpbrk(char *s, const char *accept)
{
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j] && accept[j] != s[i]; j++)
			;
		if (accept[j])
			return (s + i);
	}
	return (0x0);
}

/**
 * _strndup - Duplicates n first characters of a string
 * @str: String to duplicate
 * @n: Number of characters to duplicate
 * Return: Newly created string
 */
char *_strndup(char *str, size_t n)
{
	char *dup;
	size_t i;

	if (!str || !n)
		return (NULL);
	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
