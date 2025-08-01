/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:19:02 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/01 16:30:48 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_game *game, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.camera_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.camera_y * ray->camera_x;

	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;

	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);

	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);

	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_dist_x;
	}

	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->cubdata->map[ray->map_y][ray->map_x] != '0')
			hit = 1;
	}
}

static void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_index;
	mlx_texture_t	*tex;
	double			wall_x;
	int				tex_x;
	int				y;

	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;

	line_height = (int)(HEIGHT / ray->perp_wall_dist);

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;

	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			tex_index = TEX_NORTH;
		else
			tex_index = TEX_SOUTH;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			tex_index = TEX_WEST;
		else
			tex_index = TEX_EAST;
	}

	tex = game->textures[tex_index];

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;

	y = draw_start;
	while (y < draw_end)
	{
		int d = y * 256 - HEIGHT * 128 + line_height * 128;
		int tex_y = ((d * tex->height) / line_height) / 256;
		uint32_t *pixels = (uint32_t *)tex->pixels;
		uint32_t color = pixels[tex_y * tex->width + tex_x];
		mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}

void	cub_raycast(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, x, &ray);
		perform_dda(game, &ray);
		draw_vertical_line(game, x, &ray);
		x++;
	}
}

