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

bool	is_texture_line(const char *line)
{
	if (!line)
		return (false);
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	is_color_line(const char *line)
{
	if (!line)
		return (false);
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

bool	is_map_line(const char *line)
{
	if (!line)
		return (false);
	if (is_empty_line(line))
		return (false);
	if (is_texture_line(line))
		return (false);
	if (is_color_line(line))
		return (false);
	while (*line)
	{
		if (!ft_strchr("01 NSEW", *line))
			return (false);
		line++;
	}
	return (true);
}
