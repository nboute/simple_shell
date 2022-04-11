#include "main.h"

/**
 * _strstr - Searches for a substring in a string
 * @haystack: String to search into
 * @needle: Substring to find in @haystack
 * Return: Pointer to first occurence of @needle in @haystack
 */
char	*_strstr(char *haystack, char *needle)
{
	int	i, j;

	if (!*needle)
		return (haystack);
	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; haystack[i + j] == needle[j]; j++)
		{
			if (needle[j + 1] == '\0')
				return (haystack + i);
		}
	}
	return (0x0);
}

/**
 * _strdup_ignseq - Duplicates a string while ignoring certain bytes
 * @str: String to duplicate
 * @delim: String of bytes to ignore
 * Return: Newly created string
 */
char	*_strdup_ignseq(char *str, const char *delim)
{
	int		i, j;
	char	*new;

	j = 0;
	for (i = 0; str[i]; i++)
	{
		if (!is_in_str(str[i], delim))
			j++;
	}
	new = malloc(j + 1);
	j = 0;
	for (i = 0; str[i]; i++)
	{
		if (!is_in_str(str[i], delim))
			new[j++] = str[i];
	}
	new[j] = '\0';
	return (new);
}
