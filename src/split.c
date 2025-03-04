/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:06 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/04 19:31:01 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

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

	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		wlen = word_length(s, c);
		strs[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!strs[i])
		{
			while (i > 0)
				free(strs[--i]);
			free(strs);
			return (NULL);
		}
		j = 0;
		while (j < wlen)
			strs[i][j++] = *s++;
		strs[i][j] = '\0';
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		wcount;
	char	**strs;
	int		i;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!strs)
		return (NULL);
	strs = splitter(s, c, strs, wcount);
	if (!strs)
	{
		i = 0;
		while (i < wcount)
		{
			if (strs[i])
				free(strs[i]);
			i++;
		}
		free(strs);
		return (NULL);
	}
	strs[wcount] = NULL;
	return (strs);
}
