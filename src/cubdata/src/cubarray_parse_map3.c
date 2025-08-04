/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_map3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:04:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 18:16:22 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

static bool	is_valid_cell(char **map, int x, int y, int height)
{
	int	row_len;

	row_len = 0;
	if (x < 0 || y < 0 || x >= height)
		return (false);
	while (map[x][row_len])
		row_len++;
	if (y >= row_len)
		return (false);
	return (true);
}

static char	get_cell(char **map, int x, int y, int height)
{
	if (!is_valid_cell(map, x, y, height))
		return (' ');
	return (map[x][y]);
}

static bool	has_invalid_diagonal(char **map, int x, int y, int height)
{
	int		dx[4];
	int		dy[4];
	int		i;
	char	diag;

	i = 0;
	dx[0] = -1;
	dx[1] = -1;
	dx[2] = 1;
	dx[3] = 1;
	dy[0] = -1;
	dy[1] = 1;
	dy[2] = -1;
	dy[3] = 1;
	while (i < 4)
	{
		diag = get_cell(map, x + dx[i], y + dy[i], height);
		if (diag == ' ')
			return (true);
		i++;
	}
	return (false);
}

bool	validate_map_corners(char **map, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
			{
				if (has_invalid_diagonal(map, x, y, height))
				{
					ft_printf(2,
						"Error\n[CUB] Map must have walled corners!\n");
					return (false);
				}
			}
			y++;
		}
		x++;
	}
	return (true);
}
