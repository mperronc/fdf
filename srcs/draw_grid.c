/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:00:28 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 11:24:04 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void		draw_horizontals(t_line *l, t_map *map, t_mlx *mlx)
{
	int			line;
	int			col;

	line = 0;
	while (map->map[line])
	{
		col = 0;
		while (map->map[line][col + 1])
		{
			l = get_line_x(l, map, line, col);
			draw_line(mlx, l);
			col++;
		}
		line++;
	}
}

static void		draw_verticals(t_line *l, t_map *map, t_mlx *mlx)
{
	int			line;
	int			col;

	line = 0;
	col = 0;
	while (map->map[line][col])
	{
		line = 0;
		while (map->map[line + 1])
		{
			l = get_line_y(l, map, line, col);
			draw_line(mlx, l);
			line++;
		}
		col++;
	}
}

void			draw_grid(t_map *map, t_mlx *mlx)
{
	t_line		*l;

	l = (t_line *)malloc(sizeof(t_line));
	l->color = 0x00FFFFFF;
	draw_horizontals(l, map, mlx);
	draw_verticals(l, map, mlx);
	free(l);
}
