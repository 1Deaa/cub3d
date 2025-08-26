/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:48:33 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 18:14:05 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub_verify_args(int argc, char **argv)
{
	if (2 != argc || NULL == argv || NULL == argv[0] || NULL == argv[1])
	{
		ft_printf(2, "Error\n[ARG] Incorrect args, ");
		ft_printf(2, "Usage: %s {cub}\n", argv[0]);
		return (false);
	}
	return (true);
}

void	cub_clean(t_game *game)
{
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->textures[0])
		mlx_delete_texture(game->textures[0]);
	if (game->textures[1])
		mlx_delete_texture(game->textures[1]);
	if (game->textures[2])
		mlx_delete_texture(game->textures[2]);
	if (game->textures[3])
		mlx_delete_texture(game->textures[3]);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->cubdata)
	{
		cubdata_free(game->cubdata);
		game->cubdata = NULL;
	}
}

void	game_init(t_game *game)
{
	game->cubdata = NULL;
	game->img = NULL;
	game->mlx = NULL;
	game->textures[0] = NULL;
	game->textures[1] = NULL;
	game->textures[2] = NULL;
	game->textures[3] = NULL;
}

bool	cub_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
	{
		ft_printf(2, "Error\n[MLX] Couldn't init mlx!\n");
		return (false);
	}
	game->img = cub_img_init(game->cubdata->colors, game->mlx);
	if (!game->img)
	{
		ft_printf(2, "Error\n[MLX] Couldn't init img!\n");
		return (false);
	}
	if (!cub_load_textures(game))
		return (false);
	cub_player_init(game);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	if (!cub_verify_args(argc, argv))
		return (1);
	game.cubdata = cubdata_extract(argv[1]);
	if (!try_open_textures(&game))
	{
		cub_clean(&game);
		return (1);
	}
	if (!game.cubdata || !cub_init(&game)
		|| -1 == mlx_image_to_window(game.mlx, game.img, 0, 0))
	{
		cub_clean(&game);
		return (1);
	}
	mlx_loop_hook(game.mlx, cub_render_frame, &game);
	mlx_loop(game.mlx);
	cub_clean(&game);
	return (0);
}
