/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:50:32 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 18:50:33 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	colors_init(t_colors *colors)
{
	int	i;

	if (!colors)
		return ;
	i = 0;
	while (i < 3)
	{
		colors->c_rgb[i] = -1;
		colors->f_rgb[i] = -1;
		i++;
	}
}

static bool	colors_verify(char **raw)
{
	int		i;
	char	*line;
	int		verify[2];

	ft_memzero(verify, sizeof(verify));
	i = -1;
	while (raw[++i])
	{
		line = raw[i];
		while (*line == ' ' || *line == '\t')
			line++;
		if (ft_strncmp(line, "F ", 2) == 0)
			(verify[0])++;
		else if (ft_strncmp(line, "C ", 2) == 0)
			(verify[1])++;
		if (verify[0] > 1 || verify[1] > 1)
		{
			array_print_error(raw, i);
			ft_printf(2, "[CUB] Duplicate color was found!\n");
			return (false);
		}
	}
	return (true);
}

t_colors	*cubarray_parse_colors(char **raw)
{
	t_colors	*colors;
	int			i;

	if (!colors_verify(raw))
		return (NULL);
	colors = (t_colors *)ft_malloc(1, sizeof(t_colors));
	if (!colors)
		return (NULL);
	colors_init(colors);
	i = 0;
	while (raw[i])
	{
		if (is_color_line(raw[i]))
		{
			if (!colors_parse(colors, raw[i]))
			{
				free(colors);
				return (NULL);
			}
		}
		i++;
	}
	return (colors);
}
