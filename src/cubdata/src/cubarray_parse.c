/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:50:07 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/07 12:24:44 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

t_cubdata	*cubarray_parse(t_cubdata *cubdata)
{
	if (!cubdata)
	{
		ft_printf(2, "Error\n[DATA] Please init cubdata before using parse!\n");
		return (NULL);
	}
	if (!cubarray_validate(cubdata->raw))
	{
		cubdata_free(cubdata);
		return (NULL);
	}
	cubdata->map = cubarray_parse_map(cubdata->raw,
			&cubdata->map_height, &cubdata->map_width);
	if (!cubdata->map)
	{
		cubdata_free(cubdata);
		return (NULL);
	}
	cubdata->textures = cubarray_parse_textures(cubdata->raw);
	if (!cubdata->textures)
	{
		cubdata_free(cubdata);
		return (NULL);
	}
	cubdata->colors = cubarray_parse_colors(cubdata->raw);
	return (cubdata);
}
