/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:17:42 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 15:17:43 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel(t_img *img, int x, int y, t_color color)
{
	if (x >= 0 && x < WIN_W && y >= 0 && y <= WIN_H)
		*(int* )(img->data + ((x * img->bpp + y * img->s_line))) = color.i;
}

t_img		*ft_new_image(t_fdf *fdf)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return ((t_img *)NULL);
	img->n_img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	img->data = mlx_get_data_addr(img->n_img, &img->bpp, &img->s_line,
									 &img->endian);
	img->bpp /= 8;
	img->h = WIN_H;
	img->w = WIN_W;
	return (img);
}
