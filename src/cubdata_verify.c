/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_verify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:18:35 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/17 13:18:36 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	cubdata_verify_textures(t_cubdata *cubdata)
{
	t_textures	*textures;

	textures = cubdata->textures;
	if (!textures->ea)
	{
		ft_printf(2, "Error\n[DATA] Missing east (EA) texture!\n");
		return (false);
	}
	if (!textures->so)
	{
		ft_printf(2, "Error\n[DATA] Missing south (SO) texture!\n");
		return (false);
	}
	if (!textures->no)
	{
		ft_printf(2, "Error\n[DATA] Missing north (NO) texture!\n");
		return (false);
	}
	if (!textures->we)
	{
		ft_printf(2, "Error\n[DATA] Missing west (WE) texture!\n");
		return (false);
	}
	return (true);
}

static bool	cubdata_verify_colors(t_cubdata *cubdata)
{
	t_colors	*colors;

	colors = cubdata->colors;
	if (colors->c_rgb[0] == -1 || colors->c_rgb[1] == -1
		|| colors->c_rgb[2] == -1)
	{
		ft_printf(2, "Error\n[DATA] Missing ceiling color data!\n");
		return (false);
	}
	if (colors->f_rgb[0] == -1 || colors->f_rgb[2] == -1
		|| colors->f_rgb[3] == -1)
	{
		ft_printf(2, "Error\n[DATA] Missing floor color data!\n");
		return (false);
	}
	return (true);
}

bool	cubdata_verify(t_cubdata *cubdata)
{
	if (!cubdata)
		return (false);
	if (!cubdata->map || !cubdata->textures || !cubdata->colors)
		return (false);
	if (!cubdata_verify_textures(cubdata))
		return (false);
	if (!cubdata_verify_colors(cubdata))
		return (false);
	return (true);
}
