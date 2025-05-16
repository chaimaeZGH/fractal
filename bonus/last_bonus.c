/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/07 00:08:54 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	map(t_map a, int value)
{
	return ((value - a.old_min) * (a.new_max - a.new_min) 
		/ (a.old_max - a.old_min) + a.new_min);
}

int	phoenix_iter(double zr, double zi, t_fractalp *f)
{
	int		iter;
	double	zr_prev;
	double	zi_prev;
	double	temp;
	double	temp_prev;

	iter = 0;
	zr_prev = zr;
	zi_prev = zi;
	while (iter < MAX_ITER && (zr * zr + zi * zi) < 4.0) 
	{
		temp = zr * zr - zi * zi + f->cr + f->pr * zr_prev - f->pi * zi_prev;
		temp_prev = 2.0 * zr * zi + f->ci + f->pr * zi_prev + f->pi * zr_prev;
		zr_prev = zr;
		zi_prev = zi;
		zr = temp;
		zi = temp_prev;
		iter++;
	}
	return (iter);
}

void	creat_mand(void)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractal	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	mlx_image_to_window(window, image, 0, 0);
	fractal.window = window;
	fractal.image = image;
	creat_contun_mandal(&fractal);
	fractal.col = malloc(sizeof(t_coler));
	if (!fractal.col) 
	{
		fractal.col = NULL;
		mlx_terminate(window);
		return ;
	}
	fractal.col->i = 1;
	fractal.col->max_iter = MAX_ITER;
	mandelbrot(&fractal);
	mlx_terminate(window);
	free(fractal.col);
}
