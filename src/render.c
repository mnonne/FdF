/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:10:24 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/29 19:10:25 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		plot_pos(t_point st, t_line l_param, t_img *img)
{
	int 	x;
	int 	y;
	int 	i;

	x = (int)(st.x) + l_param.sx;
	y = (int)(st.y);
	i = 0;
	l_param.d = (l_param.dy << 1) - l_param.dx;
	l_param.d1 = l_param.dy << 1;
	l_param.d2 = (l_param.dy - l_param.dx) << 1;
	ft_put_pixel(img, (int)st.x, (int)st.y, st.color);
	while (i <= l_param.dx)
	{
		if ( l_param.d > 0)
		{
			l_param.d += l_param.d2;
			y += l_param.sy;
		}
		else
			l_param.d += l_param.d1;
		ft_put_pixel(img, x, y, st.color);
		x += l_param.sx;
		i ++;
	}
}

void		plot_neg(t_point st, t_line l_param, t_img *img)
{
	int 	x;
	int 	y;
	int 	i;

	x = (int)(st.x + l_param.sx);
	y = (int)(st.y);
	i = 0;
	l_param.d = (l_param.dx << 1) - l_param.dy;
	l_param.d1 = l_param.dx << 1;
	l_param.d2 = (l_param.dx - l_param.dy) << 1;
	ft_put_pixel(img, (int)st.x, (int)st.y, st.color);
	while (i <= l_param.dy)
	{
		if ( l_param.d > 0)
		{
			l_param.d += l_param.d2;
			x += l_param.sx;
		}
		else
			l_param.d += l_param.d1;

		ft_put_pixel(img, x, y, st.color);
		y += l_param.sy;
		i++;
	}
}

void		draw_segment(t_point st, t_point en, t_img *img)
{
	t_line	l_param;

	l_param.dx = abs((int)(en.x - st.x));
	l_param.dy = abs((int)(en.y - st.y));
	l_param.sx = en.x >= st.x ? 1 : -1;
	l_param.sy = en.y >= st.y ? 1 : -1;
	if (l_param.dy <= l_param.dx)
	{
		plot_pos(st, l_param, img);
	}
	else
	{
		plot_neg(st, l_param, img);
	}
}

void		render(t_fdf *fdf)
{
	int 	x;
	int 	y;

	fdf->img = ft_new_image(fdf);
	y = 0;
	while (y <= fdf->y_max)
	{
		x = 0;
		while (x <= fdf->x_max)
		{
			if (x + 1 <= fdf->x_max)
				draw_segment(fdf->map[y][x], fdf->map[y][x + 1], fdf->img);
			if (y + 1 <= fdf->y_max)
				draw_segment(fdf->map[y][x], fdf->map[y + 1][x], fdf->img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->n_img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
}
