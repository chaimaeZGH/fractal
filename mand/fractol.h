/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:52 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/05 22:40:41 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> 
# include "../MLX42/include/MLX42/MLX42.h"
# define MAX_ITER 1000
# define WIDTH 800
# define HEIGHT 800

typedef struct s_map
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}	t_map;

typedef struct s_fractal
{
	double		zoom;
	mlx_t		*window;
	mlx_image_t	*image;
}	t_fractal;

typedef struct s_fractalj
{
	double		zoom;
	mlx_t		*window;
	mlx_image_t	*image;
	double		a;
	double		b;
}	t_fractalj;

void	mandelbrot(t_fractal *f);
void	julia(t_fractalj *f);
void	on_key_press(struct mlx_key_data key_data, void *param);
double	map(t_map a, int value);
long	get_color(int iter, int max_iter);
int		check_dots(char *s);
double	ft_atoif(char *str);

#endif