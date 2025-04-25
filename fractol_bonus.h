/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:50 by czghoumi          #+#    #+#             */
/*   Updated: 2025/04/25 17:57:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> 
# include "./MLX42/include/MLX42/MLX42.h"
# define MAX_ITER 1000
# define WIDTH 800
# define HEIGHT 800

typedef struct s_coler
{
	int iter;
	int max_iter;
	int i;
}	t_coler;

typedef struct s_fractalp
{
	double		zoom_xmin;
	double		zoom_xmax;
	double		zoom_ymin;
	double		zoom_ymax;
	mlx_t		*window;
	mlx_image_t	*image;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	int		x_pos;
	int		y_pos;
	t_coler	*col;
	
}	t_fractalp;


typedef struct s_map
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}	t_map;

void	on_key_press(struct mlx_key_data key_data, void *param);
long	get_color(t_coler *col);
int		check_dots(char *s);
double	ft_parse_decimal(char *str, int *i, double result, double *f);
double	ft_atoif(char *str);
void	on_scroll(double xdelta, double ydelta, void *param);
int		phoenix_iter(double zr, double zi, t_fractalp *f);
void	phoenix(t_fractalp *f);
void	setup_maps(t_map *x_map, t_map *y_map, t_fractalp *f);
int		ft_strcomp(char *s1, char *s2);
double	map(t_map a, int value);

#endif