/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubarray_parse_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:51:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/16 18:51:20 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_path(char *line)
{
	if (!line)
		return (NULL);
	while (*line == ' ' || *line == '\t')
		line++;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

t_textures	*cubarray_parse_textures(char **raw)
{
	t_textures	*textures;
	int			i;
	char		*line;

	if (!raw)
		return (NULL);
	textures = ft_malloc(1, sizeof(t_textures));
	if (!textures)
		return (NULL);
	i = 0;
	while (raw[i])
	{
		line = raw[i++];
		while (*line == ' ' || *line == '\t')
			line++;
		if (ft_strncmp(line, "NO ", 3) == 0)
			textures->no = extract_path(line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			textures->so = extract_path(line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			textures->we = extract_path(line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			textures->ea = extract_path(line);
	}
	return (textures);
}
