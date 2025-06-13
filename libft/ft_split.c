/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:42:11 by drahwanj          #+#    #+#             */
/*   Updated: 2025/04/06 17:42:12 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	ft_nextsize(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **s, int n)
{
	while (n >= 0)
		free(s[n--]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;
	int		word;

	word = ft_count(s, c);
	result = ft_calloc(sizeof(char *), word + 1);
	if (!s || !result)
		return (NULL);
	j = 0;
	while (j < word)
	{
		if (*s != c)
		{
			result[j] = (char *)ft_calloc(sizeof(char), ft_nextsize(s, c) + 1);
			if (!result[j])
				return (ft_free(result, j));
			ft_strlcpy(result[j], s, ft_nextsize(s, c) + 1);
			s += ft_nextsize(s, c);
			j++;
		}
		s++;
	}
	return (result);
}
