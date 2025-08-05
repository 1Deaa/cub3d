/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:19:02 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 18:17:27 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	calculate_line_info(t_line *info, double dist)
{
	int	h;
	int	start;
	int	end;

	h = (int)(HEIGHT / dist);
	start = -h / 2 + HEIGHT / 2;
	end = h / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	info->line_height = h;
	info->draw_start = start;
	info->draw_end = end;
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	t_line			line;
	t_wall			wall;

	wall.line = &line;
	ray->perp_wall_dist = calculate_perp_wall_distance(game, ray);
	calculate_line_info(&line, ray->perp_wall_dist);
	wall.tex = select_texture(game, ray);
	wall.tex_x = calculate_texture_x(game, ray, wall.tex);
	render_wall_stripe(game, x, &wall);
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
