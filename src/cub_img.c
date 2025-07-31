/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:23:45 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/25 19:23:46 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*cub_img_init(t_colors *colors, mlx_t *mlx)
{
	uint16_t	x;
	uint16_t	y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	mlx_image_t	*img;

	ceiling_color = get_hex_color(colors->c_rgb);
	floor_color = get_hex_color(colors->f_rgb);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (NULL);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, ceiling_color);
			else
				mlx_put_pixel(img, x, y, floor_color);
		}
	}
	return (img);
}
