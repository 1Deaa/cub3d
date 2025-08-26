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

bool	try_open_textures(t_game *game)
{
	char	*list[4];
	int		fd[4];
	int		i;

	list[0] = game->cubdata->textures->we;
	list[1] = game->cubdata->textures->ea;
	list[2] = game->cubdata->textures->no;
	list[3] = game->cubdata->textures->so;
	i = 0;
	while (i < 4)
	{
		fd[i] = open(list[i], O_RDONLY);
		if (fd[i] == -1)
		{
			ft_printf(1, "Error\n[CUB] Couldn't load texture!\n");
			return (false);
		}
		close(fd[i]);
		i++;
	}
	return (true);
}

bool	cub_load_textures(t_game *game)
{
	int	i;

	game->textures[0] = mlx_load_png(game->cubdata->textures->we);
	game->textures[1] = mlx_load_png(game->cubdata->textures->ea);
	game->textures[2] = mlx_load_png(game->cubdata->textures->so);
	game->textures[3] = mlx_load_png(game->cubdata->textures->no);
	i = 0;
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
