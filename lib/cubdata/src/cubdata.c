/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:42:47 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 18:42:48 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

t_cubdata	*cubdata_init(char **cubarray)
{
	t_cubdata	*cubdata;

	if (!cubarray)
	{
		ft_printf(2, "Error\n[DATA] Please input cubarray before using init\n");
		return (NULL);
	}
	cubdata = (t_cubdata *)ft_malloc(1, sizeof(t_cubdata));
	if (!cubdata)
		return (NULL);
	cubdata->colors = NULL;
	cubdata->textures = NULL;
	cubdata->map = NULL;
	cubdata->raw = cubarray;
	return (cubdata);
}

void	cubdata_print(t_cubdata *cubdata)
{
	if (!cubdata)
		return ;
	array_print(cubdata->map);
	if (cubdata->textures)
	{
		if (cubdata->textures->no)
			ft_printf(1, "NO: %s\n", cubdata->textures->no);
		if (cubdata->textures->so)
			ft_printf(1, "SO: %s\n", cubdata->textures->so);
		if (cubdata->textures->ea)
			ft_printf(1, "EA: %s\n", cubdata->textures->ea);
		if (cubdata->textures->we)
			ft_printf(1, "WE: %s\n", cubdata->textures->we);
	}
	if (cubdata->colors)
	{
		if (cubdata->colors->f_rgb)
			ft_printf(1, "F : %d, %d, %d\n", cubdata->colors->f_rgb[0],
				cubdata->colors->f_rgb[1], cubdata->colors->f_rgb[2]);
		if (cubdata->colors->c_rgb)
			ft_printf(1, "C : %d, %d, %d\n", cubdata->colors->c_rgb[0],
				cubdata->colors->c_rgb[1], cubdata->colors->c_rgb[2]);
	}
}

void	cubdata_free(t_cubdata *cubdata)
{
	if (!cubdata)
		return ;
	array_free(cubdata->raw);
	free(cubdata->map);
	cubdata->map = NULL;
	free(cubdata->textures);
	cubdata->textures = NULL;
	free(cubdata->colors);
	cubdata->colors = NULL;
	free(cubdata);
	cubdata = NULL;
}

t_cubdata	*cubdata_extract(char *filename)
{
	t_cubdata	*cubdata;
	char		**raw_array;

	if (!cubfile_validate_extension(filename)
		|| !cubfile_validate_exist(filename)
		|| !cubfile_validate_unempty(filename))
		return (NULL);
	raw_array = cubfile_newarray(filename);
	if (!raw_array)
		return (NULL);
	cubdata = cubdata_init(raw_array);
	if (!cubdata)
	{
		array_free(raw_array);
		return (NULL);
	}
	cubdata = cubarray_parse(cubdata);
	if (!cubdata_verify(cubdata))
	{
		cubdata_free(cubdata);
		return (NULL);
	}
	return (cubdata);
}
