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

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"

typedef struct s_game
{
	char	*mapfile;
	char	**maparray;
}	t_game;

typedef struct s_textures
{
	char	*no;
	char	*we;
	char	*so;
	char	*ea;
}	t_textures;

typedef struct s_colors
{
	int	f_rgb[3];
	int	c_rgb[3];
}	t_colors;

typedef struct s_cubdata
{
	char		**raw;
	char		**map;
	t_colors	*colors;
	t_textures	*textures;
}	t_cubdata;

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

void		array_print(char **array);
void		array_free(char **array);
int			array_size(char **array);
void		array_print_error(char **array, size_t index);

int			file_open(const char *filename, int o_flag);
int			file_countlines(const char *filename);

void		mapindex_locate(char **maparray, t_index *index);
bool		mapindex_eof(char **maparray, t_index *index);
bool		mapindex_verify(t_index	*index);
char		**map_get(char **cubarray, t_index *index);


bool		main_validate_arguments(int argc, char **argv);

bool		cubfile_validate_extension(const char *file);
bool		cubfile_validate_exist(const char *file);
bool		cubfile_validate_unempty(const char *file);
char		**cubfile_newarray(const char *filename);

t_cubdata	*cubdata_init(char **cubarray);
t_cubdata	*cubdata_extract(char *filename);
void		cubdata_print(t_cubdata *cubdata);
void		cubdata_free(t_cubdata *cubdata);
bool		cubdata_verify(t_cubdata *cubdata);

t_cubdata	*cubarray_parse(t_cubdata *cubdata);
char		**cubarray_parse_map(char **raw);
t_textures	*cubarray_parse_textures(char **raw);
t_colors	*cubarray_parse_colors(char **raw);

bool		cubarray_validate(char **cubarray);

#endif