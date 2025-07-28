#include "cub3d.h"

int	main(int argc, char **argv)
{
    t_game	game;

	(void)argc;
	game.cubdata = cubdata_extract(argv[1]);
	game.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	cub_player_init(game.cubdata, &game.player);
	game.cubdata->map[1][3] = '0';
	game.img = cub_img_init(game.cubdata->colors, game.mlx);
	cubdata_print(game.cubdata);
	mlx_key_hook(game.mlx, cub_key_handler, &game);
	mlx_loop_hook(game.mlx, cub_render_frame, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	cubdata_free(game.cubdata);
	return (0);
}
