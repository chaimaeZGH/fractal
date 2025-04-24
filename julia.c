/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:58 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/26 23:01:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	on_scroll(double xdelta, double ydelta, void *param)
{
	t_fractalj	*f;

	(void)xdelta;
	f = (t_fractalj *)param;
	if (ydelta > 0)
		f->zoom = f->zoom * 0.9;
	else if (ydelta < 0)
		f->zoom = f->zoom / 0.9;
	julia(f);
}

int	julia_iter(double zr, double zi, double cr, double ci)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITER && zr * zr + zi * zi < 4.0) 
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

static long	continu_julia(int i, int j, t_map *maps, t_fractalj *f)
{
	double	zr;
	double	zi;
	int		iter;
	long	color;

	zr = map(maps[0], i);
	zi = map(maps[1], j);
	iter = julia_iter(zr, zi, f->a, f->b);
	color = get_color(iter, MAX_ITER);
	return (color);
}

static void	setup_maps(t_map *x_map, t_map *y_map, t_fractalj *f)
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

void	julia(t_fractalj *f)
{
	int		i;
	int		j;
	t_map	x_map;
	t_map	y_map;
	t_map	maps[2];

	setup_maps(&x_map, &y_map, f);
	maps[0] = x_map;
	maps[1] = y_map;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mlx_put_pixel(f->image, i, j, continu_julia(i, j, maps, f));
			i++;
		}
		j++;
	}
	mlx_key_hook(f->window, on_key_press, f);
	mlx_scroll_hook(f->window, on_scroll, f);
	mlx_loop(f->window);
}
