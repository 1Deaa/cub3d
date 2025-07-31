/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:54:16 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/31 12:54:17 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_walkable(t_cubdata *data, int x, int y)
{
	if (y < 0 || y >= data->map_height || x < 0 || x >= data->map_width)
		return (false);
	return (data->map[y][x] == '0');
}

void	cub_player_init(t_game *game)
{
	game->player.x = 		game->cubdata->pos_x;
	game->player.y = 		game->cubdata->pos_y;
	game->player.dir_x = 	game->cubdata->dir_x;
	game->player.dir_y = 	game->cubdata->dir_y;
	game->player.camera_x = game->cubdata->camera_x;
	game->player.camera_y = game->cubdata->camera_y;
}

void	cub_player_move(t_game *game, double speed)
{
	int	map_x;
	int	map_y;

	map_x = (int)(game->player.x + (game->player.dir_x * speed));
	map_y = (int)(game->player.y + (game->player.dir_y * speed));
	if (is_walkable(game->cubdata, map_x, (int)game->player.y))
		game->player.x += game->player.dir_x * speed;
	if (is_walkable(game->cubdata, (int)game->player.x, map_y))
		game->player.y += game->player.dir_y * speed;
}

void	cub_player_rotate(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_camera_x;

    old_dir_x = game->player.dir_x;
    old_camera_x = game->player.camera_x;
	game->player.dir_x = (game->player.dir_x * cos(speed))
							- (game->player.dir_y * sin(speed));
	game->player.dir_y = (old_dir_x * sin(speed))
							+ (game->player.dir_y * cos(speed));
	game->player.camera_x = (game->player.camera_x * cos(speed))
							- (game->player.camera_y * sin(speed));
	game->player.camera_y = (old_camera_x * sin(speed))
							+ (game->player.camera_y * cos(speed));
}

void	cub_player_strafe(t_game *game, double speed)
{
	double	perp_dir_x;
	double	perp_dir_y;
	int		map_x;
	int		map_y;

	perp_dir_x = game->player.dir_y;
	perp_dir_y = -game->player.dir_x;
	map_x = (int)(game->player.x + perp_dir_x * speed);
	map_y = (int)(game->player.y + perp_dir_y * speed);
    if (is_walkable(game->cubdata, map_x, (int)game->player.y))
		game->player.x += (perp_dir_x * speed);
	if (is_walkable(game->cubdata, (int)game->player.x, map_y))
		game->player.y += (perp_dir_y * speed);
}
