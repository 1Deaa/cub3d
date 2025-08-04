/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_player_direction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:57:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 18:01:01 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

static void	cubdata_player_west(t_cubdata *cubdata, char c)
{
	if (c == 'W')
	{
		cubdata->dir_x = -1;
		cubdata->dir_y = 0;
		cubdata->camera_x = 0;
		cubdata->camera_y = 0.66;
	}
}

static void	cubdata_player_direction(t_cubdata *cubdata, char c)
{
	if (c == 'N')
	{
		cubdata->dir_x = 0;
		cubdata->dir_y = 1;
		cubdata->camera_x = 0.66;
		cubdata->camera_y = 0;
	}
	else if (c == 'S')
	{
		cubdata->dir_x = 0;
		cubdata->dir_y = -1;
		cubdata->camera_x = -0.66;
		cubdata->camera_y = 0;
	}
	else if (c == 'E')
	{
		cubdata->dir_x = 1;
		cubdata->dir_y = 0;
		cubdata->camera_x = 0;
		cubdata->camera_y = -0.66;
	}
	else if (c == 'W')
		cubdata_player_west(cubdata, c);
}

void	cubdata_player_locate(t_cubdata *cubdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cubdata->map_height)
	{
		j = 0;
		while (j < cubdata->map_width)
		{
			if (ft_strchr("NSWE", cubdata->map[i][j]))
			{
				cubdata->pos_x = j + 0.5;
				cubdata->pos_y = i + 0.5;
				cubdata_player_direction(cubdata, cubdata->map[i][j]);
				cubdata->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
