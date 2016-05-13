/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:25:16 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/22 11:29:34 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <string.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200
# define WIN_CAPTION "Effe des aiphes"

typedef struct	s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			color;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct	s_map
{
	char		***map;
	int			width;
	int			height;
	int			peak;
	int			deep;
	float		z_factor;
	int			x_margin;
	int			y_margin;
	int			square_size;
	int			error;
}				t_map;

t_map			*parse_map(t_map *map, char *file);
void			draw_line(t_mlx *mlx, t_line *line);
void			print_map(char ***map);
void			draw_grid(t_map *map, t_mlx *mlx);
void			get_map_constraints(t_map *map);
int				get_x(int x, int y, t_map *map);
int				get_y(int x, int y, int z, t_map *map);
t_line			*get_line_x(t_line *l, t_map *map, int line, int col);
t_line			*get_line_y(t_line *l, t_map *map, int line, int col);
int				event_handler(int keycode, void *param);
void			free_map(t_map *map);

#endif
