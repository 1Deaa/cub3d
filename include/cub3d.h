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
#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*
Rest of the work...
*/

typedef struct s_imgs
{
    mlx_image_t	*color_img;
}	t_imgs;
typedef struct s_cub3d
{
    t_cubdata	*cubdata;
    mlx_t		*mlx;
    t_imgs        *imgs;
}	t_cub3d;
mlx_image_t	*	rgb_to_window(t_colors c, mlx_t *mlx);


#endif