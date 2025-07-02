/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:56:04 by drahwanj          #+#    #+#             */
/*   Updated: 2025/03/14 15:27:11 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *s, char c)
{
	char	temp[2];
	char	*ret;

	temp[0] = c;
	temp[1] = '\0';
	ret = ft_strjoin(s, temp);
	return (ret);
}
