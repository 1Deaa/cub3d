#include "cub3d.h"

void raycast(t_game *game)
{
    for (int x = 0; x < WIDTH; x++)
    {
        double camera_x = 2 * x / (double)WIDTH - 1; // x-coordinate in camera space
        double ray_dir_x = game->player.dir_x + game->player.camera_x * camera_x;
        double ray_dir_y = game->player.dir_y + game->player.camera_y * camera_x;

        int map_x = (int)game->player.x;
        int map_y = (int)game->player.y;

        double side_dist_x;
        double side_dist_y;

        double delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
        double delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

        int step_x;
        int step_y;

        int hit = 0; // was there a wall hit?
        int side;    // was a NS or EW wall hit?

        // Calculate step and initial sideDist
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->player.x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (game->player.y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
        }

        // Perform DDA
        while (!hit)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            // Check if ray has hit a wall
            if (game->cubdata->map[map_y][map_x] != '0')
                hit = 1;
        }

        // Calculate distance projected on camera direction
        double perp_wall_dist;
        if (side == 0)
            perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;

        // Calculate height of line to draw
        int line_height = (int)(HEIGHT / perp_wall_dist);

        // Calculate lowest and highest pixel to fill in current stripe
        int draw_start = -line_height / 2 + HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + HEIGHT / 2;
        if (draw_end >= HEIGHT)
            draw_end = HEIGHT - 1;

        // Choose wall color
        uint32_t color;
        if (side == 0)
            color = 0xFF0000FF; // Blue walls for NS
        else
            color = 0xFF00FF00; // Green walls for EW

        // Draw vertical line in image
        for (int y = draw_start; y < draw_end; y++)
        {
            mlx_put_pixel(game->img, x, y, color);
        }
    }
}

static uint32_t	get_hex_color(int *color)
{
	uint32_t	hex_color;

	hex_color = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 255;
	return (hex_color);
}

void	cub_player_strafe(t_game *game, double speed)
{
	double perp_dir_x = game->player.dir_y;
	double perp_dir_y = -game->player.dir_x;

	int	map_x = (int)(game->player.x + perp_dir_x * speed);
	int	map_y = (int)(game->player.y + perp_dir_y * speed);

    if (is_walkable(game->cubdata, map_x, (int)game->player.y))
		game->player.x += perp_dir_x * speed;
	if (is_walkable(game->cubdata, (int)game->player.x, map_y))
		game->player.y += perp_dir_y * speed;
}

bool	is_walkable(t_cubdata *data, int x, int y)
{
	if (y < 0 || y >= data->map_height || x < 0 || x >= (int)ft_strlen(data->map[y]))
		return (false);
	return (data->map[y][x] == '0');
}


void	cub_render_frame(void *param)
{
	t_game	*game = (t_game *)param;

	// Movement
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		cub_player_move(game, MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		cub_player_move(game, -MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		cub_player_strafe(game, -MOVE_SPEED);  // strafe left
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		cub_player_strafe(game, MOVE_SPEED);   // strafe right

	// View rotation
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		cub_player_rotate(game, ROTATION_SPEED);   // rotate left
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		cub_player_rotate(game, -ROTATION_SPEED);  // rotate right

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

	// Draw floor and ceiling
	uint32_t ceiling_color = get_hex_color(game->cubdata->colors->c_rgb);
	uint32_t floor_color   = get_hex_color(game->cubdata->colors->f_rgb);
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			mlx_put_pixel(game->img, x, y, (y < HEIGHT / 2) ? ceiling_color : floor_color);

	// Raycast walls
	raycast(game);

	// Present image
}

