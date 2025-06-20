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

static char	*extract_path(char *line, char **raw, int index)
{
	char	*end;
	if (!line)
		return (NULL);
	while (*line == ' ' || *line == '\t')
		line++;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	while (*line == ' ' || *line == '\t')
		line++;
	end = line;
	while (*end && *end != ' ' && *end != '\t')
		end++;
	while (*end == ' ' || *end == '\t')
		end++;
	if (*end != '\0')
	{
		array_print_error(raw, index);
		ft_printf(2, "[CUB] Texture needs to be exactly one token!\n");
		return (NULL);
	}
	return (line);
}

static void	textures_init(t_textures *textures)
{
	textures->ea = NULL;
	textures->no = NULL;
	textures->so = NULL;
	textures->we = NULL;
}

static bool	texture_verify(char **raw, int verify[4])
{
	int		i;
	char	*line;

	i = -1;
	while (raw[++i])
	{
		line = raw[i];
		while (*line == ' ' || *line == '\t')
			line++;
		if (ft_strncmp(line, "NO ", 3) == 0)
			(verify[0])++;
		else if (ft_strncmp(line, "SO ", 3) == 0)
			(verify[1])++;
		else if (ft_strncmp(line, "WE ", 3) == 0)
			(verify[2])++;
		else if (ft_strncmp(line, "EA ", 3) == 0)
			(verify[3])++;
		if (verify[0] > 1 || verify[1] > 1 || verify[2] > 1 || verify[3] > 1)
		{
			array_print_error(raw, i);
			ft_printf(2, "[CUB] Duplicate texture was found!\n");
			return (false);
		}
	}
	return (true);
}

static void	texture_parse(t_textures *textures, char *line, char **raw, int index)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		textures->no = extract_path(line, raw, index);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		textures->so = extract_path(line, raw, index);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		textures->we = extract_path(line, raw, index);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		textures->ea = extract_path(line, raw, index);
	}
}

t_textures	*cubarray_parse_textures(char **raw)
{
	t_textures	*textures;
	int			i;
	char		*line;
	int			verify[4];

	ft_memzero(verify, sizeof(verify));
	if (!texture_verify(raw, verify))
		return (NULL);
	textures = ft_malloc(1, sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures_init(textures);
	i = 0;
	while (raw[i])
	{
		line = raw[i++];
		while (*line == ' ' || *line == '\t')
			line++;
		texture_parse(textures, line, raw, i - 1);
	}
	return (textures);
}
