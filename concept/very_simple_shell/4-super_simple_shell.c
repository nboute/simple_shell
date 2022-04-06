#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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

char	**_strsplit(char *str, const char *delim)
{
	int		is_word = 0, nb_words = 0, i;
	char	**split;

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

void	free_tab(char ***tab)
{
	int	i = 0;

	if (tab && *tab)
	{
		while ((*tab)[i])
			free((*tab)[i++]);
		free((*tab));
		*(*tab) = NULL;
	}
}

int	cycle_prompt(void)
{
	char	*buf = NULL;
	size_t	i, n = 0, id = 0;
	char	**tabtokens;

	if (getline(&buf, &n, stdin) == -1)
		return (-1);
	if (buf)
	{
		tabtokens = _strsplit(buf, " \n");
		free(buf);
		buf = NULL;
		if (!tabtokens)
			return (-1);
		id = fork();
		if (!id)
		{
			if (execve(tabtokens[0], tabtokens, NULL) == -1)
				perror("ERROR:");
		}
		wait();
		free_tab(&tabtokens);
	}
}

int	main(void)
{
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		cycle_prompt();
	else
	{
		do
		{
			printf("$ ");
		} while (cycle_prompt() != -1);
	}
	return (0);
}
