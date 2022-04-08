#include "main.h"

/**
 * _strsplit - Splits string into an array of strings
 * @str: String to split
 * @delim: Array of separator bytes
 * Return: Array of strings
 */
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
	split = _memalloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	for (i = 0; i <= nb_words; i++)
		split[i] = NULL;
	for (i = 0; i < nb_words; i++)
	{
		split[i] = _strdup(_strtok(str, delim));
		if (!split[i])
		{
			while (--i >= 0)
			{
				_memdel((void *)&split[i]);
				_memdel((void *)&split);
				return (NULL);
			}
		}
		str = NULL;
	}
	return (split);
}
