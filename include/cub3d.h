/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:12:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/25 17:34:17 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cubdata.h"
# include "MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_game
{
    t_cubdata	*cubdata;
    mlx_t		*mlx;
}	t_game;

mlx_image_t	*cub_img_init(t_colors *colors, mlx_t *mlx);

#endif