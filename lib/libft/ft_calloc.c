/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:46:56 by drahwanj          #+#    #+#             */
/*   Updated: 2025/02/14 01:46:57 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			j;
	size_t			total_size;
	unsigned char	*ptr;

	j = -1;
	total_size = count * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	while (++j < total_size)
		ptr[j] = 0;
	return (ptr);
}
