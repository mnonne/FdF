/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:29:38 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/29 17:29:40 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		escape(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		free_fdf(fdf);
		exit(0);
	}
	return (0);
}

static int 		init_mlx(t_fdf **fdf)
{
	if (!((*fdf)->mlx = mlx_init()))
		return (-1);
	if (!((*fdf)->window = mlx_new_window((*fdf)->mlx, WIN_W, WIN_H, "FdF")))
		return (-1);
	return (0);
}

static int 		finish(char *message)
{
	ft_putendl_fd(message, 2);
	return (-1);
}

void			free_fdf(t_fdf *fdf)
{
	int			y;

	y = 0;
	while (y < fdf->y_max)
	{
		ft_memdel((void **)&fdf->map[y]);
		y++;
	}
//	ft_memdel((void *)&fdf->img);
	ft_memdel((void **)&fdf);
}

int 			main(int ac, char **av)
{
	t_fdf		*fdf;
	t_img		*img;

	if (ac < 2)
		return (finish("Usage: fdf [filename]"));
	if (read_fdf(&fdf, av[1]) < 0)
		return (finish("Unable to read map"));
	if (init_mlx(&fdf) < 0)
		return (finish("Unable to init mlx"));
	render(fdf);
	mlx_hook(fdf->window, 2, 5, key, fdf);
	mlx_key_hook(fdf->window, escape, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
