/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:41:12 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 11:25:03 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("Just one file please\n");
		return (0);
	}
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	map = (t_map *)malloc(sizeof(t_map));
	map = parse_map(map, argv[1]);
	if (map->error == 1)
	{
		ft_putstr("map error\n");
		return (0);
	}
	get_map_constraints(map);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_HEIGHT, WIN_WIDTH, WIN_CAPTION);
	draw_grid(map, mlx);
	free_map(map);
	mlx_key_hook(mlx->window, event_handler, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
