/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:27 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/13 11:58:27 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDATA_H
# define CUBDATA_H

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

/*
 * DATA
 *    char **raw -> the lines extracted from the file.
 *    char **map -> map matrix.
 *    int map_height
 *    int map_width
 * 
 * COLORS
 *    int f_rgb[3] -> floor rgb data.
 *    int c_rgb[3] -> ceiling rgb data.
 * 
 * TEXTURES
 *    char *no -> north texture path.
 *    char *we -> west texture path.
 *    char *so -> south texture path.
 *    char *ea -> east texture path.
 * 
 */
typedef struct s_cubdata
{
	char		**raw;
	char		**map;
	int			map_height;
	int			map_width;
	t_colors	*colors;
	t_textures	*textures;
}	t_cubdata;

/*
 * Extracts cubdata from a .cub file
 *
 * RETURN VALUE
 *     Returns a pointer to a t_cubdata structure extracted from the
 *     specified filename.
 *
 * ERRORS
 *     Returns NULL in case of an error. An error message is printed
 *     to standard error (stderr).
 */
t_cubdata	*cubdata_extract(char *filename);

/*
 * Given a pointer to a t_cubdata structure prints the data
 * inside the structure to standard output (stdout).
 * 
 * ERRORS
 *     If NULL was passed the function will print nothing.
 */
void		cubdata_print(t_cubdata *cubdata);

/*
 * Given a pointer to a t_cubdata structure frees all the
 * data inside the structure.
 */
void		cubdata_free(t_cubdata *cubdata);

#endif