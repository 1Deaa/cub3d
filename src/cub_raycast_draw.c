/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:12:05 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/05 12:12:05 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_texture_color(mlx_texture_t *tex, int tex_x, int tex_y)
{
	int			index;
	uint8_t		*pixels;
	uint32_t	color;
	t_rgba		rgba;

	pixels = tex->pixels;
	index = (tex_y * tex->width + tex_x) * 4;
	rgba.r = pixels[index + 0];
	rgba.g = pixels[index + 1];
	rgba.b = pixels[index + 2];
	rgba.a = pixels[index + 3];
	color = (rgba.r << 24) | (rgba.g << 16) | (rgba.b << 8) | rgba.a;
	return (color);
}

double	calculate_perp_wall_distance(t_game *game, t_ray *ray)
{
	double	dist;

	dist = 0;
	if (ray->side == 0)
	{
		dist = (ray->map_x - game->player.x + (1 - ray->step_x) / 2.0)
			/ ray->ray_dir_x;
	}
	else
	{
		dist = (ray->map_y - game->player.y + (1 - ray->step_y) / 2.0)
			/ ray->ray_dir_y;
	}
	return (dist);
}

mlx_texture_t	*select_texture(t_game *game, t_ray *ray)
{
	int	index;

	index = 0;
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			index = TEX_NORTH;
		else
			index = TEX_SOUTH;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			index = TEX_WEST;
		else
			index = TEX_EAST;
	}
	return (game->textures[index]);
}

int	calculate_texture_x(t_game *game, t_ray *ray, mlx_texture_t *tex)
{
	double	wall_x;
	int		tex_x;

	wall_x = 0;
	tex_x = 0;
	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	render_wall_stripe(t_game *game, int x, t_wall *wall)
{
	int			y;
	int			d;
	int			tex_y;
	uint32_t	color;

	y = wall->line->draw_start;
	while (y < wall->line->draw_end)
	{
		d = y * 256 - HEIGHT * 128 + wall->line->line_height * 128;
		tex_y = ((d * wall->tex->height) / wall->line->line_height) / 256;
		color = get_texture_color(wall->tex, wall->tex_x, tex_y);
		mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
