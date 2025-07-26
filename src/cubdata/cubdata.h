/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:58:27 by drahwanj          #+#    #+#             */
/*   Updated: 2025/07/25 17:17:35 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDATA_H
# define CUBDATA_H

/**
 * Textures for the Cub3D game.
 * @param no path of the northen texture.
 * @param we path of the western texture.
 * @param so path of the southern texture.
 * @param ea path of the eastern texture.
 */
typedef struct s_textures
{
	char	*no;
	char	*we;
	char	*so;
	char	*ea;
}	t_textures;
/**
 * Colors of the Floor and Ceiling.
 * @param f_rgb floor rgb value.
 * @param c_rgb ceiling rgb value.
 */
typedef struct s_colors
{
	int	f_rgb[3];
	int	c_rgb[3];
}	t_colors;
/**
 * @brief Textures for the Cub3D game.
 * @param raw the .cub file raw data.
 * @param map the map 2D array.
 * @param map_height the map y-axis bits.
 * @param map_width the map x-axis bits.
 * @param colors colors of the ceiling and floor.
 * @param textures textures of the walls in game. 
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

/**
 * @brief Extracts cubdata from a .cub file
 * 
 * @param filename the file you want to extract from
 * 
 * @returns
 *     a pointer to a t_cubdata structure extracted from the
 *     specified filename, NULL in case of an error.
 */
t_cubdata	*cubdata_extract(char *filename);

/**
 * @brief Given a pointer to a t_cubdata structure prints the data
 * inside the structure to standard output (stdout).
 * 
 * @param cubdata an address of t_cubdata structure.
 * 
 */
void		cubdata_print(t_cubdata *cubdata);

/**
 * @brief Given a pointer to a t_cubdata structure frees all the
 * data inside the structure.
 */
void		cubdata_free(t_cubdata *cubdata);

#endif