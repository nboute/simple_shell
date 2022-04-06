#include <stdlib.h>
#include <stdio.h>

/**
 * _strpbrk - Searches for any of the bytes of a substring in another string
 * @s: String to search into
 * @accept: Set of bytes to search
 * Return: Pointer to first match
 */
char	*_strpbrk(char *s, const char *accept)
{
	int	i, j;

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
 * _strndup - Creates a duplicate of the first n characters of a string
 * @str: String to duplicate
 * @n: Number of characters to duplicate
 * Return: Newly created string
 */
char	*_strndup(char *str, size_t n)
{
	char	*dup;
	size_t	i;

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

/**
 * is_in_str - Tells if a character is in a string
 * @c: Character to search for
 * @str: String to search in
 * Return: 1 if @c is found, 0 if not
 */
int		is_in_str(char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

/**
 * _strtok - Breaks a string into tokens and returns first token
 * @str: String to tokenize
 * @delim: Array of delimiter bytes to cut string with
 * Return: String token
 */
char	*_strtok(char *str, const char *delim)
{
	static char	*ptr = NULL;
	char		*next, *tok = NULL;
	size_t		len;

	if (str)
		ptr = str;
	while (ptr && is_in_str(*ptr, delim))
		ptr++;
	if (!*ptr)
		return (NULL);
	next = _strpbrk(ptr, delim);
	if (next || *ptr)
	{
		if (next)
			len = next - ptr;
		else
		{
			for (len = 0; ptr[len]; len++)
				;
		}
		tok = _strndup(ptr, len);
	}
	ptr = next;
	while (ptr && is_in_str(*ptr, delim))
		ptr++;
	return (tok);
}

/**
 * _strsplit - Splits string into array of strings
 * @str: String to split
 * @delim: Array of delimiter bytes to cut string with
 * Return: Array of strings
 */
char	**_strsplit(char *str, const char *delim)
{
	int		state_word = 0, nb_words = 0, i;
	char	**split;

	if (!str || !delim)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (!state_word && !is_in_str(str[i], delim))
		{
			nb_words++;
			state_word = 1;
		}
		if (is_in_str(str[i], delim))
			state_word = 0;
	}
	split = malloc(sizeof(char*) * (nb_words + 1));
	if (!split)
		return (NULL);
	for (i = 0; i <= nb_words; i++)
		split[i] = NULL;
	for (i = 0; i < nb_words; i++)
	{
		split[i] = _strtok(str, delim);
		if (!split[i])
		{
			while (--i >= 0)
			{
				free(split[i]);
				free(split);
				return (NULL);
			}
		}
		str = NULL;
	}
	return (split);
}
