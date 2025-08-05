/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:23:00 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 18:23:23 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_hex_color(int *color)
{
	uint32_t	hex_color;

	hex_color = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 255;
	return (hex_color);
}

mlx_image_t	*cub_img_init(t_colors *colors, mlx_t *mlx)
{
	uint16_t	x;
	uint16_t	y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	mlx_image_t	*img;

	ceiling_color = get_hex_color(colors->c_rgb);
	floor_color = get_hex_color(colors->f_rgb);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (NULL);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, ceiling_color);
			else
				mlx_put_pixel(img, x, y, floor_color);
		}
	}
	return (img);
}

void	cub_clear_screen(t_cubdata *cubdata, mlx_image_t *img)
{
	uint32_t	c_color;
	uint32_t	f_color;
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	c_color = get_hex_color(cubdata->colors->c_rgb);
	f_color = get_hex_color(cubdata->colors->f_rgb);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				mlx_put_pixel(img, x, y, c_color);
			else
				mlx_put_pixel(img, x, y, f_color);
			x++;
		}
		y++;
	}
}

void	cub_render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		cub_player_move(game, MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		cub_player_move(game, -MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		cub_player_strafe(game, -MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		cub_player_strafe(game, MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		cub_player_rotate(game, ROTATION_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		cub_player_rotate(game, -ROTATION_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	cub_clear_screen(game->cubdata, game->img);
	cub_raycast(game);
}
