/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maparray_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:50:07 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/14 19:50:08 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mapdata_init(t_mapdata *mapdata)
{
	mapdata->we_path = NULL;
	mapdata->ea_path = NULL;
	mapdata->so_path = NULL;
	mapdata->no_path = NULL;
	mapdata->c_color = NULL;
	mapdata->f_color = NULL;
	mapdata->map = NULL;
}

void	maparray_parse(t_mapdata *mapdata, char **raw_array)
{
	mapdata_init(mapdata);
	(void)raw_array;
}
