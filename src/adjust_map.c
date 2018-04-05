/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:49:29 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 11:49:31 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		ft_round(double nb)
{
	return (nb <= (int)nb + 0.5) ? ((int)nb) : ((int)nb + 1);
}

t_point		reduce(t_point point, double res)
{
	t_point	new;

	new.x = point.x / res;
	new.y = point.y / res;
	new.z = point.z / res;
	new.color = point.color;
	return (new);
}

void		adjust_map(t_fdf **fdf)
{
	int 	x;
	int 	y;
	double 	d_z;

	SEGMENT = (WIN_H - 100) / 2 / (*fdf)->y_max;
	d_z = ((*fdf)->z_max + (*fdf)->z_min) / 2 * SEGMENT;
	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			MAP_POINT = enlarge(MAP_POINT, SEGMENT);
			MAP_POINT = move(MAP_POINT, MOVE_X, MOVE_Y, -d_z);
			x++;
		}
		y++;
	}
}
