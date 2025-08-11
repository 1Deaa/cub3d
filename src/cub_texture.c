/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:00:52 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/05 00:00:53 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub_load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures[0] = mlx_load_png(game->cubdata->textures->we);
	game->textures[1] = mlx_load_png(game->cubdata->textures->ea);
	game->textures[2] = mlx_load_png(game->cubdata->textures->so);
	game->textures[3] = mlx_load_png(game->cubdata->textures->no);
	while (i < 4)
	{
		if (NULL == game->textures[i])
		{
			ft_printf(2, "Error\n[MLX] Failed to load texture %d\n", i + 1);
			return (false);
		}
		i++;
	}
	return (true);
}
