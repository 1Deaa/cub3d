/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:11:05 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/14 17:11:06 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

/*
Checks wether the map file extension is correct or not.
*/
bool	cubfile_validate_extension(const char *file)
{
	const char	*map_file;
	char		*ext;

	map_file = file;
	if (!map_file)
	{
		ft_printf(2, "Error\n[CUB] No valid map file, input required!\n");
		return (false);
	}
	ext = ft_strrchr(map_file, '.');
	if (!ext)
	{
		ft_printf(2, "Error\n[CUB] Invalid map extension: no extension!\n");
		return (false);
	}
	if (ft_strncmp(ext, ".cub", 4) != 0)
	{
		ft_printf(2, "Error\n[CUB] Invalid map extension: %s!\n", ext);
		return (false);
	}
	return (true);
}

/*
Checks wether target map file exist or not.
*/
bool	cubfile_validate_exist(const char *file)
{
	int	fd;

	fd = file_open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

/*
Checks wether the map file is empty or not.
*/
bool	cubfile_validate_unempty(const char *file)
{
	int		fd;
	char	buffer;
	size_t	bytes;

	fd = file_open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	bytes = read(fd, &buffer, 1);
	close(fd);
	if (bytes < 1)
	{
		ft_printf(2, "Error\n[CUB] %s: file is empty!\n", file);
		return (false);
	}
	return (true);
}
