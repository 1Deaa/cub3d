/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:42:29 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/04 11:42:30 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

int	array_max_width(char **array)
{
	int	i;
	int	max;
	int	cur;

	i = 0;
	max = 0;
	cur = 0;
	while (array && array[i])
	{
		cur = ft_strlen(array[i]);
		if (cur > max)
		{
			max = cur;
		}
		i++;
	}
	return (max);
}

void	array_free_i(char **array, size_t index)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] && i < index)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
