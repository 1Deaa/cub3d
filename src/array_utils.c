/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:43:50 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:51 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	array_print(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array && array[i])
	{
		ft_printf(1, "%s", array[i]);
		i++;
	}
}

void	array_free(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
