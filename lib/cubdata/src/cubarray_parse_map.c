/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:50:41 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 18:50:41 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

char	**map_get(char **cubarray, t_index *index)
{
	char	**map;
	int		size;
	int		i;
	int		j;

	if (!cubarray || !index)
		return (NULL);
	if (!mapindex_verify(index))
		return (NULL);
	size = index->end - index->start + 1;
	map = (char **)ft_malloc(size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = index->start;
	j = 0;
	while (i <= index->end)
	{
		map[j++] = cubarray[i++];
	}
	map[j] = NULL;
	return (map);
}

bool	is_valid_player(char **map)
{
	int		player_cnt;

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

void	normalize_line(char *old, char *new, int width)
{
	int	i;

	i = 0;
	while (old[i])
	{
		if (old[i] == ' ')
			new[i] = '1';
		else
			new[i] = old[i];
		i++;
	}
	while (i < width)
	{
		new[i] = '1';
		i++;
	}
	new[i] = '\0';
}

char	**normalize_map(char **map, int width)
{
	char	**new_map;
	int		height;
	int		i;

	height = array_size(map);
	new_map = (char **)ft_malloc(height + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_malloc(width + 1, sizeof(char));
		if (!new_map[i])
		{
			array_free_i(new_map, i);
			return (NULL);
		}
		normalize_line(map[i], new_map[i], width);
		i++;
	}
	new_map[height] = NULL;
	return (new_map);
}

char	**cubarray_parse_map(char **raw)
{
	t_index	map_index;
	char	**map;
	char	**norm;

	mapindex_locate(raw, &map_index);
	if (!mapindex_eof(raw, &map_index))
		return (NULL);
	if (!mapindex_verify(&map_index))
		return (NULL);
	map = map_get(raw, &map_index);
	if (!is_valid_player(map))
	{
		free(map);
		return (NULL);
	}
	norm = normalize_map(map, array_max_width(map));
	free(map);
	return (norm);
}
