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

uint32_t	get_hex_color(int *color)
{
	uint32_t	hex_color;

	hex_color = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 255;
	return (hex_color);
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
	t_game	*game = (t_game *)param;
	static struct timeval	prev_time = {0};
	struct timeval			curr_time;
	double					elapsed_time = 0.0;
	double					fps = 0.0;
	char					fps_str[32];
	static mlx_image_t		*last_fps_img = NULL;

	if (last_fps_img)
		mlx_delete_image(game->mlx, last_fps_img);

	gettimeofday(&curr_time, NULL);

	if (prev_time.tv_sec != 0)
	{
		elapsed_time = (curr_time.tv_sec - prev_time.tv_sec) + (curr_time.tv_usec - prev_time.tv_usec) / 1000000.0;
		fps = 1.0 / elapsed_time;
	}
	prev_time = curr_time;

	/* Player & Camera Movement */
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

	/* Reset Screen */
	cub_clear_screen(game->cubdata, game->img);

	/* Raycast walls */
	cub_raycast(game);
	if (fps > 0.0)
	{
		snprintf(fps_str, sizeof(fps_str), "FPS: %.2f", fps);
		last_fps_img = mlx_put_string(game->mlx, fps_str, 10, 10);
	}
}

// void	cub_render_frame(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
// 		cub_player_move(game, MOVE_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
// 		cub_player_move(game, -MOVE_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
// 		cub_player_strafe(game, -MOVE_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
// 		cub_player_strafe(game, MOVE_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		cub_player_rotate(game, ROTATION_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		cub_player_rotate(game, -ROTATION_SPEED);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	cub_clear_screen(game->cubdata, game->img);
// 	cub_raycast(game);
// }
