/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:44:40 by drahwanj          #+#    #+#             */
/*   Updated: 2025/03/13 22:22:14 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = -1;
	len = 0;
	if (n <= 0)
		return (NULL);
	while (len < n && s[len] != '\0')
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}
