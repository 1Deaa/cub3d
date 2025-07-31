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

bool	is_floodable(char c)
{
	if (c == '0')
		return (true);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_valid_flood_cell(t_mapinfo *info, int x, int y)
{
	if (x < 0 || x >= info->height)
		return (false);
	if (y < 0 || y >= (int)ft_strlen(info->map[x]))
		return (false);
	if (info->map[x][y] == ' ')
		return (false);
	if (!is_floodable(info->map[x][y]))
		return (false);
	if (info->visited[x][y])
		return (false);
	return (true);
}

bool	flood_fill(t_mapinfo *info, int x, int y)
{
	if (x < 0 || x >= info->height || y < 0 || y >= ft_strlen(info->map[x]))
		return (true);
	if (info->map[x][y] == ' ')
		return (false);
	if (!is_floodable(info->map[x][y]) || info->visited[x][y])
		return (true);
	if (x == 0 || y == 0 || x == info->height - 1 || y == ft_strlen(info->map[x]) - 1)
		return (false);
	info->visited[x][y] = true;
	if (!flood_fill(info, x - 1, y))
		return (false);
	if (!flood_fill(info, x + 1, y))
		return (false);
	if (!flood_fill(info, x, y - 1))
		return (false);
	if (!flood_fill(info, x, y + 1))
		return (false);
	return (true);
}

bool	validate_map(char **map, int height)
{
	t_mapinfo info;
	int i;
	int j;

	info.map = map;
	info.height = height;
	info.visited = malloc(sizeof(bool *) * height);
	i = 0;
	while (i < height)
	{
		int row_len = ft_strlen(map[i]);
		info.visited[i] = malloc(sizeof(bool) * row_len);
		j = 0;
		while (j < row_len)
		{
			info.visited[i][j] = false;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		int row_len = ft_strlen(map[i]);
		j = 0;
		while (j < row_len)
		{
			if (is_floodable(map[i][j]) && !info.visited[i][j])
				if (!flood_fill(&info, i, j))
					return (false);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		free(info.visited[i]);
		i++;
	}
	free(info.visited);
	return (true);
}
