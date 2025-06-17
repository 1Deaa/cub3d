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

#include "cub3d.h"

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

char	**cubarray_parse_map(char **raw)
{
	t_index	map_index;
	char	**map;

	mapindex_locate(raw, &map_index);
	if (!mapindex_eof(raw, &map_index))
		return (NULL);
	if (!mapindex_verify(&map_index))
		return (NULL);
	map = map_get(raw, &map_index);
	return (map);
}
