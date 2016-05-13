/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:48:15 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 09:56:20 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		get_x(int x, int y, t_map *map)
{
	int ret;

	ret = (((0.5 * x) - (0.5 * y)) * map->square_size + map->x_margin);
	return (ret);
}

int		get_y(int x, int y, int z, t_map *map)
{
	int ret;

	ret = ((((0.5 / 2) * x) + ((0.5 / 2) * y) - map->z_factor * z) *
			map->square_size + map->y_margin);
	return (ret);
}

t_line	*get_line_x(t_line *l, t_map *map, int line, int col)
{
	l->x0 = get_x(col, line, map);
	l->y0 = get_y(col, line, ft_atoi(map->map[line][col]), map);
	l->x1 = get_x(col + 1, line, map);
	l->y1 = get_y(col + 1, line, ft_atoi(map->map[line][col + 1]), map);
	return (l);
}

t_line	*get_line_y(t_line *l, t_map *map, int line, int col)
{
	l->x0 = get_x(col, line, map);
	l->y0 = get_y(col, line, ft_atoi(map->map[line][col]), map);
	l->x1 = get_x(col, line + 1, map);
	l->y1 = get_y(col, line + 1, ft_atoi(map->map[line + 1][col]), map);
	return (l);
}
