#include "cub3d.h"

void	cub_player_init(t_cubdata *data, t_player *player)
{
    (void)data;
	player->x = 2;
	player->y = 1.5;
	player->dir_x = -1;
	player->dir_y = 0;
	player->camera_x = 0;
	player->camera_y = 0.66;
}

void	cub_player_move(t_game *game, double speed)
{
	int	map_x;
	int	map_y;

	map_x = (int)(game->player.x + (game->player.dir_x * speed));
	map_y = (int)(game->player.y + (game->player.dir_y * speed));
	if (game->cubdata->map[(int)game->player.y][map_x] == '0')
	{
		game->player.x += game->player.dir_x * speed;
	}
	if (game->cubdata->map[(int)game->player.y][map_y] == '0')
	{
		game->player.y += game->player.dir_y * speed;
	}
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
