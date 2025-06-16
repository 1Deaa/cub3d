/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapindex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:03:54 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 13:03:55 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_line(const char *line)
{
	int	i;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}	
	return (true);
}

bool	is_map_line(const char *line)
{
	if (!line)
		return (false);
	if (is_empty_line(line))
		return (false);
	while (*line)
	{
		if (!ft_strchr("01 NSEW", *line))
			return (false);
		line++;
	}
	return (true);
}

void	mapindex_locate(char **cubarray, t_index *index)
{
	int	i;

	if (!cubarray || !index)
		return ;
	index->end = -1;
	index->start = -1;
	i = 0;
	while (cubarray[i])
	{
		if (is_map_line(cubarray[i]))
		{
			index->start = i;
			break ;
		}
		i++;
	}
	if (index->start == -1)
		return ;
	while (cubarray[i] && is_map_line(cubarray[i]))
	{
		index->end = i;
		i++;
	}
}

bool	mapindex_eof(char **cubarray, t_index *index)
{
	int	i;

	if (!cubarray)
		return (true);
	i = index->end + 1;
	while (cubarray[i])
	{
		if (!is_empty_line(cubarray[i]))
		{
			array_print_error(cubarray, i);
			ft_printf(2, "[CUB] Map must be at the end of file!\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	mapindex_verify(t_index	*index)
{
	if (index->start == -1 || index->end == -1)
	{
		ft_printf(2, "Error\n[CUB] Map was not found in the file!\n");
		return (false);
	}
	if (index->start == index->end)
	{
		ft_printf(2, "Error\n[CUB] Map cannot be 1 line!\n");
		return (false);
	}
	if (index->end < index->start)
	{
		ft_printf(2, "Error\n[CUB] Incorrect indexing start > end!\n");
		return (false);
	}
	return (true);
}
