/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:57:05 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 11:38:21 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int		count_lines(int fd)
{
	int		n_lines;
	char	*line;

	n_lines = 0;
	while (get_next_line(fd, &line))
	{
		n_lines++;
		free(line);
	}
	return (n_lines);
}

static int		count_length(char **phrase, t_map *map)
{
	int i;

	i = 0;
	while (phrase[i])
	{
		if (ft_atoi(phrase[i]) > map->peak)
			map->peak = ft_atoi(phrase[i]);
		if (ft_atoi(phrase[i]) < map->deep)
			map->deep = ft_atoi(phrase[i]);
		i++;
	}
	return (i);
}

static void		build_map(int fd, t_map *map)
{
	int		i;
	int		width;
	char	*line;

	i = 0;
	width = -1;
	while (i < map->height)
	{
		get_next_line(fd, &line);
		map->map[i] = ft_strsplit(line, ' ');
		if (map->map[i] == NULL)
		{
			map->error = 1;
			break ;
		}
		if (width == -1)
			width = count_length(map->map[i], map);
		else if (count_length(map->map[i], map) != width)
			map->error = 1;
		free(line);
		i++;
	}
	map->width = width;
	map->map[i] = 0;
}

t_map			*parse_map(t_map *map, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		map->error = 1;
		return (map);
	}
	map->height = count_lines(fd);
	map->peak = 0;
	map->deep = 0;
	if (map->height == 0)
	{
		map->error = 1;
		return (map);
	}
	map->map = (char ***)malloc(sizeof(char **) * (map->height + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	build_map(fd, map);
	close(fd);
	return (map);
}
