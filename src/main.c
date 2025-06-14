/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:42 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/13 11:58:43 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_mapdata	mapdata;

	(void)argv;
	(void)argc;
	game.mapfile = argv[1];
	game.maparray = mapfile_newarray(game.mapfile);
	maparray_parse(&mapdata, game.maparray);
	array_print(game.maparray);
	array_free(game.maparray);
	// main_validate_arguments(argc, argv);
	// mapfile_validate_exist(game.mapfile);
	// mapfile_validate_extension(game.mapfile);
	// mapfile_validate_unempty(game.mapfile);
}
