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

/*
Checks wether the argument count is correct or not.
*/
bool	validate_main_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf(2, "Error\nInvalid arguments, Usage: %s (*.cub)\n", argv[0]);
		return (false);
	}
	return (true);
}

/*
Checks wether the map file extension is correct or not.
*/
bool	validate_mapfile_extension(const char *file)
{
	const char	*map_file;
	char		*ext;

	map_file = file;
	if (!map_file)
	{
		ft_printf(2, "Error\nNo valid map file input .cub required!\n");
		return (false);
	}
	ext = ft_strrchr(map_file, '.');
	if (!ext)
	{
		ft_printf(2, "Error\nInvalid map extension: no extension!\n");
		return (false);
	}
	if (ft_strncmp(ext, ".cub", 4) != 0)
	{
		ft_printf(2, "Error\nInvalid map extension: %s!\n", ext);
		return (false);
	}
	return (true);
}

/*
Checks wether target map file exist or not.
*/
bool	validate_mapfile_exist(const char *file)
{
	int	fd;

	if (!file)
	{
		ft_printf(2, "Error\nNo valid map file input .cub required!\n");
		return (false);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "Error\n%s: doesn't exist or cannot be opened!\n", file);
		return (false);
	}
	close(fd);
	return (true);
}

/*
Checks wether the map file is empty or not.
*/
bool	validate_mapfile_unempty(const char *file)
{
	int		fd;
	char	buffer;
	size_t	bytes;

	if (!file)
	{
		ft_printf(2, "Error\nNo valid map file input .cub required!\n");
		return (false);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "Error\n%s: doesn't exist or cannot be opened!\n", file);
		return (false);
	}
	bytes = read(fd, &buffer, 1);
	close(fd);
	if (bytes < 1)
	{
		ft_printf(2, "Error\n%s: file is empty!\n", file);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	game.mapfile = argv[1];
	validate_main_arguments(argc, argv);
	validate_mapfile_exist(game.mapfile);
	validate_mapfile_extension(game.mapfile);
	validate_mapfile_unempty(game.mapfile);
}
