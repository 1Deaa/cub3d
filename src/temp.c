/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:42 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/26 17:13:07 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"

// cub3d_minimal.c
#include "MLX42.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

typedef struct s_player {
    double x, y;         // position
    double dir_x, dir_y; // direction vector
    double plane_x, plane_y; // camera plane (FOV)
} t_player;

typedef struct s_game {
    mlx_t *mlx;
    mlx_image_t *img;
    t_player player;
    int map[MAP_HEIGHT][MAP_WIDTH];
} t_game;

// Hardcoded map: 1 = wall, 0 = empty space
int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void raycast(t_game *game)
{
    for (int x = 0; x < WIDTH; x++)
    {
        double camera_x = 2 * x / (double)WIDTH - 1; // x-coordinate in camera space
        double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
        double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

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
            if (game->map[map_y][map_x] > 0)
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

void move_player(t_game *game, double move_speed)
{
    int map_x = (int)(game->player.x + game->player.dir_x * move_speed);
    int map_y = (int)(game->player.y + game->player.dir_y * move_speed);

    if (game->map[(int)game->player.y][map_x] == 0)
        game->player.x += game->player.dir_x * move_speed;
    if (game->map[map_y][(int)game->player.x] == 0)
        game->player.y += game->player.dir_y * move_speed;
}

void strafe_player(t_game *game, double move_speed)
{
    double strafe_x = game->player.dir_y;
    double strafe_y = -game->player.dir_x;

    int map_x = (int)(game->player.x + strafe_x * move_speed);
    int map_y = (int)(game->player.y + strafe_y * move_speed);

    if (game->map[(int)game->player.y][map_x] == 0)
        game->player.x += strafe_x * move_speed;
    if (game->map[map_y][(int)game->player.x] == 0)
        game->player.y += strafe_y * move_speed;
}

void rotate_player(t_game *game, double rot_speed)
{
    double old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
    game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
    double old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
    game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}

void handle_key(mlx_key_data_t keydata, void *param)
{
    t_game *game = param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_W)
            move_player(game, MOVE_SPEED);
        else if (keydata.key == MLX_KEY_S)
            move_player(game, -MOVE_SPEED);
        else if (keydata.key == MLX_KEY_A)
            strafe_player(game, -MOVE_SPEED);
        else if (keydata.key == MLX_KEY_D)
            strafe_player(game, MOVE_SPEED);
        else if (keydata.key == MLX_KEY_LEFT)
            rotate_player(game, -ROT_SPEED);
        else if (keydata.key == MLX_KEY_RIGHT)
            rotate_player(game, ROT_SPEED);
        else if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx);
    }
}

void render_frame(void *param)
{
    t_game *game = param;

    // Clear screen (black)
    mlx_image_to_window(game->mlx, game->img, 0, 0);
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            mlx_put_pixel(game->img, x, y, 0x000000FF);
    raycast(game);

    mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int main(void)
{
    t_game game;

    // Copy map
    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            game.map[y][x] = worldMap[y][x];

    // Init player position and direction
    game.player.x = 12;
    game.player.y = 12;
    game.player.dir_x = -1;
    game.player.dir_y = 0;
    game.player.plane_x = 0;
    game.player.plane_y = 0.66; // 66 degree FOV

    game.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D Minimal Raycasting", false);
    if (!game.mlx)
    {
        printf("Failed to init MLX42\n");
        return 1;
    }

    game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
    if (!game.img)
    {
        printf("Failed to create image\n");
        mlx_terminate(game.mlx);
        return 1;
    }

    mlx_key_hook(game.mlx, handle_key, &game);
    mlx_loop_hook(game.mlx, render_frame, &game);

    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return 0;
}

