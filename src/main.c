/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:48:33 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/30 19:48:34 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub_verify_args(int argc, char **argv)
{
	if (2 != argc || NULL == argv || NULL == argv[0] || NULL == argv[1])
	{
		ft_printf(2, "Error\nIncorrect args:");
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

	cub_player_init(&game); //TODO

	game.img = cub_img_init(game.cubdata->colors, game.mlx);

	mlx_image_to_window(game.mlx, game.img, 0, 0);

	mlx_loop_hook(game.mlx, cub_render_frame, &game);

	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);

	cubdata_free(game.cubdata);

	return (0);
}
