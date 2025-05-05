/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:55 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/05 18:41:50 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double cr, double ci)
{
	double	zr;
	double	zi;
	int		iter;
	double	temp;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	while (iter < MAX_ITER && zr * zr + zi * zi < 4.0) 
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

static void	on_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	(void)xdelta;
	f = (t_fractal *)param; 
	if (ydelta > 0)
		f->zoom *= 0.9;
	else if (ydelta < 0)
		f->zoom /= 0.9;
	mandelbrot(f);
}

static long	continu_mandel(int i, int j, t_map x_map, t_map y_map)
{
	double	cr;
	double	ci;
	int		iter;
	long	color;

	cr = map(x_map, i);
	ci = map(y_map, j);
	iter = mandelbrot_iter(cr, ci);
	color = get_color(iter, MAX_ITER);
	return (color);
}

static void	setup_maps(t_map *x_map, t_map *y_map, t_fractal *f)
{
	x_map->old_min = 0;
	x_map->old_max = WIDTH;
	x_map->new_min = -2.0 * f->zoom;
	x_map->new_max = 2.0 * f->zoom;
	y_map->old_min = 0;
	y_map->old_max = HEIGHT;
	y_map->new_min = -2.0 * f->zoom;
	y_map->new_max = 2.0 * f->zoom;
}

void	mandelbrot(t_fractal *f)
{
	int		i;
	int		j;
	t_map	x_map;
	t_map	y_map;

	setup_maps(&x_map, &y_map, f);
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mlx_put_pixel(f->image, i, j, continu_mandel(i, j, x_map, y_map));
			i++;
		}
		j++;
	}
	mlx_key_hook(f->window, on_key_press, f);
	mlx_scroll_hook(f->window, on_scroll, f);
	mlx_loop(f->window);
}
