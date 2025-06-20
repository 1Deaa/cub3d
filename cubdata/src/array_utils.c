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

#include "cubdata_internal.h"

void	array_print(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array && array[i])
	{
		ft_printf(1, "[%d] %s\n", i, array[i]);
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
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	array_size(char **array)
{
	int	i;

	if (!array)
		return (-1);
	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

int	array_print_error(char **array, size_t index)
{
	size_t	i;

	if (!array)
		return (0);
	i = 0;
	ft_printf(2, "Error\n");
	while (array && array[i])
	{
		if (i == index)
		{
			ft_printf(2, RED"✕ [%d] %s\n"RESET, i + 1, array[i]);
			break ;
		}
		else
		{
			ft_printf(2, GREEN"✓ [%d] %s\n"RESET, i + 1, array[i]);
		}
		i++;
	}
	return (0);
}
