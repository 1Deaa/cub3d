/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:35:47 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/21 00:35:48 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDATA_INTERNAL_H
# define CUBDATA_INTERNAL_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include "../cubdata.h"

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"

typedef struct s_mapinfo
{
	char	**map;
	bool	**visited;
	int		width;
	int		height;
}	t_mapinfo;

typedef struct s_index
{
	int	start;
	int	end;
}	t_index;

void		*ft_malloc(size_t count, size_t size);

bool		is_empty_line(const char *line);
bool		is_map_line(const char *line);
bool		is_texture_line(const char *line);
bool		is_color_line(const char *line);
bool		is_valid_player(char **map);
bool		is_closed_walls(char **map, int height, int width);

void		array_print(char **array);
void		array_free(char **array);
void		array_free_i(char **array, size_t index);
int			array_size(char **array);
int			array_print_error(char **array, size_t index);
int			array_count_target(char **array, char target[]);
int			array_max_width(char **array);
int			array_width(char **array);

int			file_open(const char *filename, int o_flag);
int			file_countlines(const char *filename);

void		mapindex_locate(char **maparray, t_index *index);
bool		mapindex_eof(char **maparray, t_index *index);
bool		mapindex_verify(t_index	*index);
char		**map_get(char **cubarray, t_index *index);

bool		cubfile_validate_extension(const char *file);
bool		cubfile_validate_exist(const char *file);
bool		cubfile_validate_unempty(const char *file);
char		**cubfile_newarray(const char *filename);

t_cubdata	*cubdata_init(char **cubarray);
bool		cubdata_verify(t_cubdata *cubdata);

t_cubdata	*cubarray_parse(t_cubdata *cubdata);
char		**cubarray_parse_map(char **raw, int *height, int *width);
t_textures	*cubarray_parse_textures(char **raw);
t_colors	*cubarray_parse_colors(char **raw);
t_colors	*colors_parse(t_colors *colors, char *line);

bool		cubarray_validate(char **cubarray);
void		cubdata_player_locate(t_cubdata *cubdata);

bool		validate_map(char **map, int height, int width);
bool		flood_fill(t_mapinfo *info, int x, int y);
bool		run_flood_checks(t_mapinfo *info, int height, int width);
bool		is_valid_flood_cell(t_mapinfo *info, int x, int y);
bool		is_floodable(char c);

#endif