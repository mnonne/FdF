/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:31:47 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/31 13:31:49 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	key(int key, t_fdf *fdf)
{
	if (key == 126 || key == 125 || key == 123 || key == 124)
		move_map(&fdf, key);
	else if (key == 7 || key == 6)
		rotate_map_z(&fdf, key);
	else if (key == 12 || key == 13)
		rotate_map_y(&fdf, key);
	else if (key == 0 || key == 1)
		rotate_map_x(&fdf, key);
	else if (key == 24 || key == 27)
		resize(&fdf, key);
	render(fdf);
	return (0);
}
