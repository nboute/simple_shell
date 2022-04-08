#include "main.h"

/**
 * _strjoin - Concatenates two string together into a new one
 * @s1: First string
 * @s2: Second string
 * Return: Newly created string
 */
char	*_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len1, len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (_strdup(s1));
	if (!s2)
		return (_strdup(s2));
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	join = _memalloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	_strcpy(join, s1);
	_strcpy(join + len1, s2);
	return (join);
}
