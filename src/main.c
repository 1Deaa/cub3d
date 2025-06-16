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
	t_cubdata	*cubdata;

	(void)argv;
	(void)argc;
	game.mapfile = argv[1];
	game.maparray = cubfile_newarray(game.mapfile); // [+] HEAP ALLOCATION
	cubdata = cubdata_init(game.maparray); 			// [+] HEAP ALLOCATION
	cubdata = cubarray_parse(cubdata);				// [+] [+] HEAP ALLOCATION
	//array_print(game.maparray);
	free(cubdata->textures);    // [-] HEAP DEALLOCATION
	free(cubdata->map);			// [-] HEAP DEALLOCATION
	array_free(game.maparray);  // [-] HEAP DEALLOCATION
	free(cubdata); 				// [-] HEAP DEALLOCATION
	/*		FINAL STEP
		FAILURE = FREE EVERYTHING BEFORE - EXIT
		SUCCESS = CONTINUE
	*/
}
