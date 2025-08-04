/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:12:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/08/04 17:15:48 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cubdata.h"
# include "MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"

# define WIDTH 1280
# define HEIGHT 720
# define MOVE_SPEED 0.04
# define ROTATION_SPEED 0.05
# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_WEST  2
# define TEX_EAST  3

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	camera_x;
	double	camera_y;
}	t_player;

typedef struct s_game
{
	t_cubdata		*cubdata;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	mlx_texture_t	*textures[4];
}	t_game;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}	t_ray;

uint32_t	get_hex_color(int *color);

mlx_image_t	*cub_img_init(t_colors *colors, mlx_t *mlx);

void		cub_render_frame(void *param);

void		cub_raycast(t_game *game);

void		cub_player_init(t_game *game);

void		cub_player_move(t_game *game, double speed);

void		cub_player_rotate(t_game *game, double speed);

void		cub_player_strafe(t_game *game, double speed);

bool		is_walkable(t_cubdata *data, int x, int y);

void		init_ray(t_game *game, int x, t_ray *ray);

bool		cub_load_textures(t_game *game);

#endif