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

void	normalize_line(char *old, char *new, int width)
{
	int	i;

	i = 0;
	while (old[i] && i < width)
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

	if (!map)
		return (NULL);
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

char	**cubarray_parse_map(char **raw, int *height, int *width)
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
	norm = normalize_map(map, array_max_width(map));
	free(map);
	if (!norm)
		return (NULL);
	*height = array_size(norm);
	*width = array_max_width(norm);
	if (!is_valid_player(norm) || !is_closed_walls(norm, *height, *width))
	{
		array_free(norm);
		return (NULL);
	}
	return (norm);
}
