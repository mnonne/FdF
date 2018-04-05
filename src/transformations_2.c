/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:28 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 14:52:29 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		resize(t_fdf **fdf, int key)
{
	int 	x;
	int 	y;

	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			APEX = move(APEX, -(WIN_W / 2), -(WIN_H / 2), 0);
			if (key == 24)
				APEX = enlarge(APEX, 1.1111);
			else
				APEX = reduce(APEX, 1.1111);
			APEX = move(APEX, (WIN_W / 2), (WIN_H / 2), 0);
			x++;
		}
		y++;
	}
}

void		rotate_map_y(t_fdf **fdf, int key)
{
	int 	x;
	int 	y;

	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			APEX = move(APEX, -(WIN_W / 2), -(WIN_H / 2), 0);
			if (key == 12)
				APEX = rotate_y(APEX, 1);
			else if (key == 13)
				APEX = rotate_y(APEX, -1);
			APEX = move(APEX, (WIN_W / 2), (WIN_H / 2), 0);
			x++;
		}
		y++;
	}
}

void		rotate_map_x(t_fdf **fdf, int key)
{
	int 	x;
	int 	y;

	y = 0;
	while (y <= (*fdf)->y_max)
	{
		x = 0;
		while (x <= (*fdf)->x_max)
		{
			APEX = move(APEX, -(WIN_W / 2), -(WIN_H / 2), 0);
			if (key == 1)
				APEX = rotate_x(APEX, 1);
			else if (key == 0)
				APEX = rotate_x(APEX, -1);
			APEX = move(APEX, (WIN_W / 2), (WIN_H / 2), 0);
			x++;
		}
		y++;
	}
}

t_point		rotate_y(t_point point, double angle)
{
	t_point	new;
	double	sine;
	double	cosine;
	double	x;
	double 	z;

	x = point.x;
	z = point.z;
	sine = sin(RAD(angle));
	cosine = cos(RAD(angle));
	new.x = x * cosine + z * sine;
	new.z = z * cosine - x * sine;
	new.y = point.y;
	new.color = point.color;
	return (new);
}

t_point		rotate_x(t_point point, double angle)
{
	t_point	new;
	double	sine;
	double	cosine;
	double	y;
	double 	z;

	y = point.y;
	z = point.z;
	sine = sin(RAD(angle));
	cosine = cos(RAD(angle));
	new.y = y * cosine + z * sine;
	new.z = z * cosine - y * sine;
	new.x = point.x;
	new.color = point.color;
	return (new);
}
