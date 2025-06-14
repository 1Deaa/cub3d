/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:27 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/13 11:58:27 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_game
{
	char	*mapfile;
	char	**maparray;
}	t_game;

typedef struct s_mapdata
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_color;
	char	*c_color;
	char	**map;
}	t_mapdata;

void	*ft_malloc(size_t count, size_t size);
void	array_print(char **array);
void	array_free(char **array);

int		file_open(const char *filename, int o_flag);
char	**mapfile_newarray(const char *filename);
int		file_countlines(const char *filename);

bool	main_validate_arguments(int argc, char **argv);
bool	mapfile_validate_extension(const char *file);
bool	mapfile_validate_exist(const char *file);
bool	mapfile_validate_unempty(const char *file);

void	maparray_parse(t_mapdata *mapdata, char **raw_array);

#endif