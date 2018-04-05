/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:06:23 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 12:06:24 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map_z(t_fdf **fdf, int key)
{
	int x;
	int y;

	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			APEX = move(APEX, -(WIN_W / 2), -(WIN_H / 2), 0);
			if (key == 7)
				APEX = rotate_z(APEX, 1);
			else if (key == 6)
				APEX = rotate_z(APEX, -1);
			APEX = move(APEX, (WIN_W / 2), (WIN_H / 2), 0);
			x++;
		}
		y++;
	}
}

void	move_map(t_fdf **fdf, int key)
{
	int x;
	int y;

	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			if (key == 126)
				APEX = move(APEX, 0, -10, 0);
			else if (key == 125)
				APEX = move(APEX, 0, 10, 0);
			else if (key == 123)
				APEX = move(APEX, -10, 0, 0);
			else if (key == 124)
				APEX = move(APEX, 10, 0, 0);
			x++;
		}
		y++;
	}
}

t_point		rotate_z(t_point point, double angle)
{
	t_point	new;
	double 	sine;
	double 	cosine;
	double 	x;
	double 	y;

	x = point.x;
	y = point.y;
	sine = sin(RAD(angle));
	cosine = cos(RAD(angle));
	new.x = x * cosine - y * sine;
	new.y = x * sine + y * cosine;
	new.z = point.z;
	new.color = point.color;
	return (new);
}

t_point		move(t_point point, int x, int y, int z)
{
	t_point	new;

	new.x = point.x + x;
	new.y = point.y + y;
	new.z = point.z + z;
	new.color = point.color;
	return (new);
}

t_point		enlarge(t_point point, double res)
{
	t_point	new;

	new.x = point.x * res;
	new.y = point.y * res;
	new.z = point.z * res;
	new.color = point.color;
	return (new);
}
