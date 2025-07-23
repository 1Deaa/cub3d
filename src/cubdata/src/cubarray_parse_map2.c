/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_map2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:58:23 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/04 14:58:24 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

bool	is_valid_player(char **map)
{
	int		player_cnt;

	if (!map)
		return (false);
	player_cnt = array_count_target(map, "NSWE");
	if (player_cnt == 0)
	{
		ft_printf(2, "Error\n[MAP] No player was found in the map!\n");
		return (false);
	}
	if (player_cnt != 1)
	{
		ft_printf(2, "Error\n[MAP] Only 1 player is allowed in the map!\n");
		return (false);
	}
	return (true);
}

bool	is_closed_width(char **map, int width, int height)
{
	int	x;

	x = -1;
	while (++x < width)
	{
		if (map[height - 1][x] != '1')
		{
			array_print_error(map, height - 1);
			ft_printf(2, "[MAP] Map is not fully enclosed by walls!\n");
			return (false);
		}
		if (map[0][x] != '1')
		{
			array_print_error(map, 0);
			ft_printf(2, "[MAP] Map is not fully enclosed by walls!\n");
			return (false);
		}
	}
	return (true);
}

bool	is_closed_height(char **map, int height, int width)
{
	int	y;

	y = -1;
	while (++y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
		{
			array_print_error(map, y);
			ft_printf(2, "[MAP] Map is not fully enclosed by walls!\n");
			return (false);
		}
	}
	return (true);
}

bool	is_closed_walls(char **map, int height, int width)
{
	if (!is_closed_height(map, height, width))
		return (false);
	if (!is_closed_width(map, width, height))
		return (false);
	return (true);
}
