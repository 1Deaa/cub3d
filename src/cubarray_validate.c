/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:01:01 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 18:01:02 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_identifier(const char *line)
{
	if (!line)
		return (true);
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

static bool	is_valid_line(const char *line)
{
	if (is_empty_line(line))
		return (true);
	if (is_valid_identifier(line))
		return (true);
	if (is_map_line(line))
		return (true);
	return (false);
}

bool	cubarray_validate(char **cubarray)
{
	int	i;

	i = 0;
	while (cubarray && cubarray[i])
	{
		if (!is_valid_line(cubarray[i]))
		{
			array_print_error(cubarray, i);
			ft_printf(2, "[CUB] Invalid .cub configuration unknown data!\n");
			return (false);
		}
		i++;
	}
	return (true);
}
