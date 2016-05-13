/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:16:17 by mperronc          #+#    #+#             */
/*   Updated: 2016/03/10 15:36:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void		print_map(char ***map)
{
	int		line;
	int		word;

	line = 0;
	while (map[line])
	{
		word = 0;
		while (map[line][word])
		{
			ft_putstr(map[line][word]);
			ft_putchar(' ');
			word++;
		}
		ft_putchar('\n');
		line++;
	}
}
