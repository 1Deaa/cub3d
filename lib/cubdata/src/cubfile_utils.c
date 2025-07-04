/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:19:34 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/14 17:19:34 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubdata_internal.h"

/*
Allocates memory of specific size.
*/
void	*ft_malloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	full;

	if (count > SIZE_MAX / size)
	{
		ft_printf(2, "Error\n[MEM] Requested size too large %d * %d!\n",
			count, size);
		return (NULL);
	}
	full = size * count;
	if (size < 1 || count < 1)
	{
		ft_printf(2, "Error\n[MEM] Can't allocate negative value %d!\n", count);
		return (NULL);
	}
	ptr = malloc(full);
	if (!ptr)
	{
		ft_printf(2, "Error\n[MEM] Couldn't allocate memory of %d bytes!\n",
			full);
		return (NULL);
	}
	return (ptr);
}

/*
Opens a file and returns an fd.
*/
int	file_open(const char *filename, int o_flag)
{
	int	fd;

	if (!filename)
	{
		ft_printf(2, "Error\n[FILE] No valid map file, input required!\n");
		return (-1);
	}
	fd = open(filename, o_flag);
	if (fd == -1)
	{
		ft_printf(2, "Error\n[FILE] %s: doesn't exist or cannot be opened!\n",
			filename);
		return (-1);
	}
	return (fd);
}

/*
Counts how many lines in a file.
*/
int	file_countlines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = file_open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**file_newarray_fill(char **array, int fd, int lines_count)
{
	char	*line;
	char	*newline;
	int		i;

	if (!array || fd == -1 || lines_count == -1)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		newline = ft_strchr(line, '\n');
		if (newline)
			*newline = '\0';
		array[i] = line;
		line = get_next_line(fd);
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*
Creates an array copy of the file.
*/
char	**cubfile_newarray(const char *filename)
{
	int		fd;
	int		lines_count;
	char	**array;

	fd = file_open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines_count = file_countlines(filename);
	array = (char **)ft_malloc(lines_count + 1, sizeof(char *));
	if (!array)
	{
		close(fd);
		return (NULL);
	}
	array = file_newarray_fill(array, fd, lines_count);
	close(fd);
	return (array);
}
