/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:45:22 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/10 15:59:41 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#define DX (abs(l->x1 - l->x0))
#define DY (abs(l->y1 - l->y0))

void	draw_line(t_mlx *mlx, t_line *l)
{
	int sx;
	int sy;
	int err;
	int err2;

	sx = l->x0 < l->x1 ? 1 : -1;
	sy = l->y0 < l->y1 ? 1 : -1;
	err = (DX > DY ? DX : -DY) / 2;
	while (1)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, l->x0, l->y0, l->color);
		if (DX <= 1 && DY <= 1)
			break ;
		err2 = err;
		if (err2 > -DX)
		{
			err -= DY;
			l->x0 += sx;
		}
		if (err2 < DY)
		{
			err += DX;
			l->y0 += sy;
		}
	}
}
