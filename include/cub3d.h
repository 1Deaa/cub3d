/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:12:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/28 18:33:56 by yousef           ###   ########.fr       */
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
# define ROTATION_SPEED 0.02

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
	t_cubdata	*cubdata;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	player;
}	t_game;

uint32_t	get_hex_color(int *color);

mlx_image_t	*cub_img_init(t_colors *colors, mlx_t *mlx);

void		cub_render_frame(void *param);

void		cub_raycast(t_game *game);

void		cub_player_init(t_game *game);

void		cub_player_move(t_game *game, double speed);

void		cub_player_rotate(t_game *game, double speed);

void		cub_player_strafe(t_game *game, double speed);

void		cub_key_handler(mlx_key_data_t keydata, void *param);

bool		is_walkable(t_cubdata *data, int x, int y);


#endif