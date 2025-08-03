/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:48:33 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/01 16:27:16 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cub_load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures[0] = mlx_load_png(game->cubdata->textures->no);
	game->textures[1] = mlx_load_png(game->cubdata->textures->so);
	game->textures[2] = mlx_load_png(game->cubdata->textures->ea);
	game->textures[3] = mlx_load_png(game->cubdata->textures->we);
	while (i < 4)
	{
		if (NULL == game->textures[i])
		{
			ft_printf(2, "Error\n[CUB] Failed to load texture %d\n", i);
			cubdata_free(game->cubdata);
			return (1);
		}
		i++;
	}
	{
		if (!game->textures[i])
			return (1);
	}
	return (0);
}


bool	cub_verify_args(int argc, char **argv)
{
	if (2 != argc || NULL == argv || NULL == argv[0] || NULL == argv[1])
	{
		ft_printf(2, "Error\n[ARG] Incorrect args:");
		ft_printf(2, "Usage: %s {cub}\n", argv[0]);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
    t_game	game;

	if (!cub_verify_args(argc, argv))
		return (1);

	game.cubdata = cubdata_extract(argv[1]);
	if (!game.cubdata)
		return (false);

	game.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);

	cub_player_init(&game);

	game.img = cub_img_init(game.cubdata->colors, game.mlx);

	mlx_image_to_window(game.mlx, game.img, 0, 0);
	
	cub_load_textures(&game);

	mlx_loop_hook(game.mlx, cub_render_frame, &game);

	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);

	cubdata_print(game.cubdata);

	cubdata_free(game.cubdata);

	return (0);
}
