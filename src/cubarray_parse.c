/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:50:07 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/14 19:50:08 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cubdata	*cubarray_parse(t_cubdata *cubdata)
{
	if (!cubdata)
	{
		ft_printf(2, "Error\n[DATA] Please init cubdata before using parse!\n");
		return (NULL);
	}
	cubarray_validate(cubdata->raw);
	cubdata->map = cubarray_parse_map(cubdata->raw);
	cubdata->textures = cubarray_parse_textures(cubdata->raw);
	cubdata->colors = cubarray_parse_colors(cubdata->raw);
	return (cubdata);
}
