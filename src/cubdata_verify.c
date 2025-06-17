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

/*Add !cubdata->colors*/
bool	cubdata_verify(t_cubdata *cubdata)
{
	if (!cubdata)
		return (false);
	if (!cubdata->map || !cubdata->textures)
		return (false);
	if (!cubdata_verify_textures(cubdata))
		return (false);
	return (true);
}
