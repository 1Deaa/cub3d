/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_colors_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:59:41 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/19 12:59:41 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	skip_leading_whitespace(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (**str != '\0');
}

static bool	validate_trailing(char *end)
{
	while (*end == ' ' || *end == '\t')
		end++;
	return (*end == '\0' || *end == '\n');
}

static bool	parse_single_color(char **str, int *value, int is_last)
{
	char	*end;

	*value = ft_atoi(*str);
	if (*value < 0 || *value > 255)
	{
		ft_printf(2, "Error\n[CUB] Color must be between [0-255]!\n");
		return (false);
	}
	end = *str;
	while (*end && *end != ',')
		end++;
	if (!is_last && *end != ',')
	{
		ft_printf(2, "Error\n[CUB] Expected a comma ',' between RGB values!\n");
		return (false);
	}
	if (is_last && !validate_trailing(end))
	{
		ft_printf(2, "Error\n[CUB] Unexpected chars after last RGB value!\n");
		return (false);
	}
	*str = end + 1;
	return (true);
}

static bool	parse_rgb(char *str, int rgb[3])
{
	int	i;

	if (!skip_leading_whitespace(&str))
	{
		ft_printf(2, "Error\n[CUB] RGB line is empty or only whitespaces!\n");
		return (false);
	}
	i = 0;
	while (i < 3)
	{
		if (!parse_single_color(&str, &rgb[i], i == 2))
			return (false);
		i++;
	}
	return (true);
}

t_colors	*colors_parse(t_colors *colors, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (!parse_rgb(line + 2, colors->f_rgb))
		{
			ft_printf(2, "[CUB] Invalid floor color format!\n");
			return (NULL);
		}
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (!parse_rgb(line + 2, colors->c_rgb))
		{
			ft_printf(2, "[CUB] Invalid ceiling color format!\n");
			return (NULL);
		}
	}
	return (colors);
}
