/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:42 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/25 17:32:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;

	(void)argc;
	game.cubdata = cubdata_extract(argv[1]);
	game.mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	mlx_image_to_window(game.mlx, cub_img_init(game.cubdata->colors, game.mlx), 0, 0);
	mlx_loop(game.mlx);
	cubdata_free(game.cubdata);
	mlx_terminate(game.mlx);
}
