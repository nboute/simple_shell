#include "main.h"

int is_in_str(char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char *_strtok(char *str, const char *delim)
{
	static char *ptr = NULL;
	char *next, *tok = NULL;
	size_t len;

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

char **_strsplit(char *str, const char *delim)
{
	int is_word = 0, nb_words = 0, i;
	char **split;

	if (!str || !delim)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (!is_word && !is_in_str(str[i], delim))
		{
			nb_words++;
			is_word = 1;
		}
		if (is_in_str(str[i], delim))
			is_word = 0;
	}
	split = malloc(sizeof(char *) * (nb_words + 1));
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

void free_tab(char ***tab)
{
	int i = 0;

	if (tab && *tab)
	{
		while ((*tab)[i])
			free((*tab)[i++]);
		free((*tab));
		*tab = NULL;
	}
}
