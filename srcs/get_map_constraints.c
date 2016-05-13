/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_constraints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:22:10 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 11:59:23 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include <stdio.h>

void	get_map_constraints(t_map *map)
{
	map->square_size = ft_min2(WIN_HEIGHT, WIN_WIDTH)
						/ ft_max2(map->height, map->width);
	map->x_margin = WIN_WIDTH / 2;
	map->y_margin = WIN_HEIGHT / 2;
	map->z_factor = 2.0 / (float)ft_max2(map->peak - map->deep, 1);
}
