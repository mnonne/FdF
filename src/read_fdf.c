/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:36:37 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/29 17:36:39 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_color		get_color(char *str)
{
	t_color	color;
	int 	nb;

	if ((str = ft_strchr(str, ',')) != NULL)
	{
		color.i = 0;
		str += 3;
		nb = ft_hextoi(str);
		color.c.r = (unsigned char)(nb >> 16);
		color.c.g =	(unsigned char)(nb >> 8 & 0xFF);
		color.c.b = (unsigned char)(nb & 0xFF);
	}
	else
		color.i = 0xFFFFFF;
	return (color);
}

t_point 	*fill_map(t_fdf **fdf, char *line, int y)
{
	char 	**tab;
	t_point	*arr;
	int 	tab_s;
	int 	x;

	tab = ft_strnsplit(line, ' ', &tab_s);
	arr = (t_point *)malloc(sizeof(t_point) * tab_s);
	x = 0;
	while (*tab)
	{
		arr[x].x = x;
		arr[x].y = y;
		arr[x].z = ft_atoi(*tab);
		arr[x].color = get_color(*tab);
		if (arr[x].z < (*fdf)->z_min)
			(*fdf)->z_min = (int)arr[x].z;
		if (arr[x].z > (*fdf)->z_max)
			(*fdf)->z_max = (int)arr[x].z;
		x++;
		tab++;
	}
	(*fdf)->x_max = x - 1;
	return (arr);
}

int 		count_lines(char *file)
{
	int 	i;
	int 	fd;
	char 	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int			read_fdf(t_fdf **fdf, char *file)
{
	char	*line;
	int 	fd;
	int 	line_nbr;
	int 	lines;

	if ((lines = count_lines(file)) < 0)
		return (-1);
	if (!(*fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (-1);
	if (!((*fdf)->map = (t_point **)malloc(sizeof(t_point) * lines)))
		return (-1);
	(*fdf)->z_min = 0;
	(*fdf)->z_max = 0;
	fd = open(file, O_RDONLY);
	line_nbr = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*fdf)->map[line_nbr] = fill_map(fdf, line, line_nbr);
		free(line);
		line_nbr++;
	}
	(*fdf)->y_max = line_nbr - 1;
	(*fdf)->img = NULL;
	adjust_map(fdf);
	return (0);
}
