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

#include "cub3d.h"

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
	ft_memzero(cubdata, sizeof(t_cubdata));
	cubdata->raw = cubarray;
	return (cubdata);
}

bool	cubdata_verify(t_cubdata *cubdata)
{
	(void)cubdata;
	return (false);
}
