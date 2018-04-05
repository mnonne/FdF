/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:43:38 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 16:43:40 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_bg(t_fdf *fdf)
{
	int 	x;
	int 	y;

	y = 0;
	while (y < 98)
	{
		x = 0;
		while (x <= WIN_W)
		{
			mlx_pixel_put(fdf->mlx, fdf->window, x, y, G_COLOR);
			x++;
		}
		y++;
	}
	x = 0;
	while (x++ <= WIN_W)
		mlx_pixel_put(fdf->mlx, fdf->window, x, y, 0xFFFFFF);
}

void		draw_menu(t_fdf *fdf)
{

	draw_bg(fdf);
	mlx_string_put(fdf->mlx, fdf->window, 1200, 35, 0xFFFFFF, "FdF by aminadzh");
	mlx_string_put(fdf->mlx, fdf->window, 40, 10, 0xFFFFFF, "Zoom in: +");
	mlx_string_put(fdf->mlx, fdf->window, 40, 40, 0xFFFFFF, "Zoom out: -");
	mlx_string_put(fdf->mlx, fdf->window, 40, 70, 0xFFFFFF, "Move: arrow keys");
	mlx_string_put(fdf->mlx, fdf->window, 2350, 10, 0xFFFFFF, "Rotate by Z: z, x");
}
