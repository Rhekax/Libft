/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:55 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/14 15:16:20 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*delete(char **s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free (s);
	return (NULL);
}

static int	counter(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*wordfiller(const char *s, char c)
{
	int			wordcount;
	int			i;
	char		*string;
	const char	*copied;

	i = 0;
	wordcount = 0;
	copied = s;
	while (*s != c && *s)
	{
		wordcount++;
		s++;
	}
	string = (char *) malloc (sizeof(char) * (wordcount + 1));
	if (!string)
		return (NULL);
	while (i < wordcount)
	{
		string[i++] = *copied++;
	}
	string[i] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		wordcount;

	i = 0;
	wordcount = counter(s, c);
	strings = (char **) malloc (sizeof(char *) * (wordcount + 1));
	if (!strings)
		return (NULL);
	while (i < wordcount)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strings[i] = wordfiller(s, c);
			if (!strings[i])
				return (delete (strings, i));
			while (*s && *s != c)
				s++;
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
