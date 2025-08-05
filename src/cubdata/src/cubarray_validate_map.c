/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_validate_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:31:46 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/31 16:31:47 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

static bool	**allocate_visited(int height, int width)
{
	bool	**visited;
	int		i;
	int		j;

	visited = ft_malloc(height, sizeof(bool *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_malloc(width, sizeof(bool));
		if (!visited[i])
		{
			array_free_i((char **)visited, i);
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (visited);
}

static void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

bool	validate_map(char **map, int height, int width)
{
	t_mapinfo	info;

	info.map = map;
	info.height = height;
	info.visited = allocate_visited(height, width);
	if (!info.visited)
		return (false);
	if (!run_flood_checks(&info, height, width))
	{
		free_visited(info.visited, height);
		ft_printf(2, "Error\nIncorrect map shape!\n");
		return (false);
	}
	free_visited(info.visited, height);
	return (true);
}
