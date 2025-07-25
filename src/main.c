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
#include "MLX42.h"

int	main(int argc, char **argv)
{
	t_cub3d		*cub3d;
	
	cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (EXIT_FAILURE);
	}
	cub3d->imgs = malloc(sizeof(t_imgs));
	if (!cub3d->imgs)
	{
		fprintf(stderr, "Failed to allocate imgs\n");
		return (EXIT_FAILURE);
	}
	
	(void)argc;
	cub3d->cubdata = cubdata_extract(argv[1]);
	cubdata_print(cub3d->cubdata);
	cub3d->mlx = mlx_init(1280, 720, "Cub3d", false);
	cub3d->imgs->color_img = rgb_to_window(*cub3d->cubdata->colors, cub3d->mlx);
	mlx_loop(cub3d->mlx);
	cubdata_free(cub3d->cubdata);
	mlx_terminate(cub3d->mlx);
}
