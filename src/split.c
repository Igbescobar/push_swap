/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:06 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:38 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

int	word_length(char const *s, char c)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (s[i] != c && s[i])
	{
		length++;
		i++;
	}
	return (length);
}

char	**splitter(char const *s, char c, char **strs, int wcount)
{
	int	i;
	int	j;
	int	wlen;

	while (*s == c)
		s++;
	i = -1;
	while (++i < wcount)
	{
		while (*s == c)
			s++;
		j = 0;
		wlen = word_length(s, c);
		strs[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!(strs[i]))
			return (NULL);
		while (j < wlen)
		{
			strs[i][j] = *s;
			s++;
			j++;
		}
		strs[i][j] = '\0';
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		wcount;
	char	**strs;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!(strs))
		return (NULL);
	strs = splitter(s, c, strs, wcount);
	strs[wcount] = NULL;
	return (strs);
}
