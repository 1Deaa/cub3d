#include "cub3d.h"

void	cub_key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
            cub_player_move(game, MOVE_SPEED);
        else if (keydata.key == MLX_KEY_S)
            cub_player_move(game, -MOVE_SPEED);
        else if (keydata.key == MLX_KEY_D)
            cub_player_rotate(game, -ROTATION_SPEED);
        else if (keydata.key == MLX_KEY_A)
            cub_player_rotate(game, ROTATION_SPEED);
        else if (keydata.key == MLX_KEY_ESCAPE)
        {
            mlx_close_window(game->mlx);
            cubdata_free(game->cubdata);
        }
	}
}
