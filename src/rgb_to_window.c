#include "cub3d.h"

mlx_image_t	*rgb_to_window(t_colors c, mlx_t *mlx)
{
	int			x;
	int			y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	mlx_image_t	*img;

	ceiling_color = (255 << 24) | (c.c_rgb[0] << 16) | (c.c_rgb[1] << 8) | c.c_rgb[2];
	floor_color   = (255 << 24) | (c.f_rgb[0] << 16) | (c.f_rgb[1] << 8) | c.f_rgb[2];
	img = mlx_new_image(mlx, 1280, 720);
	if (!img)
		return (NULL);
	y = -1;
	while (++y < 720) // height
	{
		x = -1;
		while (++x < 1280) // width
		{
			if (y < 720 / 2)
				mlx_put_pixel(img, x, y, ceiling_color);
			else
				mlx_put_pixel(img, x, y, floor_color);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	return (img);
}

