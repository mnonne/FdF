/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:04:37 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/16 17:04:39 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "../libft/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>//

# define G_COLOR 0x0080FF
# define WIN_W 2560
# define WIN_H 1315
# define SEGMENT (*fdf)->segment
# define APEX (*fdf)->map[y][x]
# define MOVE_X (WIN_W) / 2 - (*fdf)->x_max * (SEGMENT) / 2
# define MOVE_Y (WIN_H) / 2 - (*fdf)->y_max * (SEGMENT) / 2
# define MAP_POINT (*fdf)->map[y][x]
# define RAD(x) (x * (M_PI / 180))

typedef struct		s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_rgb;

typedef union 		u_color
{
	t_rgb			c;
	int 			i;
}					t_color;

typedef struct		s_point
{
	double 			x;
	double 			y;
	double 			z;
	t_color			color;
}					t_point;

typedef struct		s_img
{
	void			*n_img;
	char			*data;
	int 			bpp;
	int 			s_line;
	int 			endian;
	int 			h;
	int 			w;
}					t_img;

typedef struct		s_fdf
{
	int 			x_max;
	int 			y_max;
	int 			z_min;
	int 			z_max;
	int 			segment;
	void			*mlx;
	void			*window;
	t_point			**map;
	t_img			*img;
}					t_fdf;

typedef struct		s_line
{
	int 			dx;
	int 			dy;
	int 			sx;
	int 			sy;
	int 			d;
	int 			d1;
	int 			d2;
}					t_line;

void				free_fdf(t_fdf *fdf);

/*
** read_fdf.c
*/
int					read_fdf(t_fdf **fdf, char *file);
t_point 			*fill_map(t_fdf **fdf, char *line, int y);
t_color				get_color(char *str);
int 				count_lines(char *file);

/*
** add this to lib
*/
char				**ft_strnsplit(char const *s, char c, int *tab_s);
int 				ft_hextoi(char *str);

/*
** render.c
*/
void				render(t_fdf *fdf);

/*
** adjust_map.c
*/
void				adjust_map(t_fdf **fdf);
t_point				reduce(t_point point, double res);
int 				ft_round(double nb);

/*
** transformations.c
*/
t_point				enlarge(t_point point, double res);
t_point				move(t_point point, int x, int y, int z);
t_point				rotate_z(t_point point, double angle);
void				move_map(t_fdf **map, int key);
void				rotate_map_z(t_fdf **fdf, int key);

/*
** transformations_2.c
*/
void				rotate_map_x(t_fdf **fdf, int key);
void				rotate_map_y(t_fdf **fdf, int key);
t_point				rotate_x(t_point point, double angle);
t_point				rotate_y(t_point point, double angle);
void				resize(t_fdf **fdf, int key);

/*
** hookers.c
*/
int 				key(int key, t_fdf *fdf);

/*
** image.c
*/
t_img				*ft_new_image(t_fdf *fdf);
void				ft_put_pixel(t_img *img, int x, int y, t_color color);

#endif
