/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/09 12:30:08 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	on_key_press(struct mlx_key_data key_data, void *param)
{
	t_fractalp	*f;

	f = (t_fractalp *)param;
	if (key_data.action == MLX_RELEASE)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->window);
		else if (key_data.key == 49 && f->col->i < 20)
			f->col->i++;
		else if (key_data.key == 50 && f->col->i > 1)
			f->col->i--;
		else if (key_data.key == MLX_KEY_UP)
			handle_franmep(f, 0.0, -0.02);
		else if (key_data.key == MLX_KEY_DOWN)
			handle_franmep(f, 0.0, 0.02);
		else if (key_data.key == MLX_KEY_LEFT)
			handle_franmep(f, -0.02, 0.0);
		else if (key_data.key == MLX_KEY_RIGHT)
			handle_franmep(f, 0.02, 0.0);
		phoenix(f);
	}
}

static long	continu_ph(int i, int j, t_map *maps, t_fractalp *f)
{
	double	zr;
	double	zi;
	int		iter;
	long	color;

	zr = map(maps[0], i);
	zi = map(maps[1], j);
	iter = phoenix_iter(zr, zi, f);
	f->col->iter = iter;
	color = get_color(f->col);
	return (color);
}

static void	setup_maps(t_map *x_map, t_map *y_map, t_fractalp *f)
{
	x_map->old_min = 0;
	x_map->old_max = WIDTH;
	x_map->new_min = -2.0 * f->zoom_xmin;
	x_map->new_max = 2.0 * f->zoom_xmax;
	y_map->old_min = 0;
	y_map->old_max = HEIGHT;
	y_map->new_min = -2.0 * f->zoom_ymin;
	y_map->new_max = 2.0 * f->zoom_ymax;
}

static void	on_scroll(double xdelta, double ydelta, void *param)
{
	t_fractalp	*f;
	double		mouse_real_x; 
	double		mouse_real_y;
	double		zoom_factor;

	(void)xdelta;
	f = (t_fractalp *)param;
	mlx_get_mouse_pos(f->window, &f->x_pos, &f->y_pos);
	mouse_real_x = (-2.0 * f->zoom_xmin) + ((double)f->x_pos / WIDTH) * 
		((2.0 * f->zoom_xmax) - (-2.0 * f->zoom_xmin));
	mouse_real_y = (-2.0 * f->zoom_ymin) + ((double)f->y_pos / HEIGHT) * 
		((2.0 * f->zoom_ymax) - (-2.0 * f->zoom_ymin));
	if (ydelta > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	f->zoom_xmin = (mouse_real_x + ((-2.0 * f->zoom_xmin) - 
				mouse_real_x) * zoom_factor) / -2.0;
	f->zoom_xmax = (mouse_real_x + ((2.0 * f->zoom_xmax) - 
				mouse_real_x) * zoom_factor) / 2.0;
	f->zoom_ymin = (mouse_real_y + ((-2.0 * f->zoom_ymin) - 
				mouse_real_y) * zoom_factor) / -2.0;
	f->zoom_ymax = (mouse_real_y + ((2.0 * f->zoom_ymax) - 
				mouse_real_y) * zoom_factor) / 2.0;
	phoenix(f);
}

void	phoenix(t_fractalp *f)
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
			mlx_put_pixel(f->image, i, j, continu_ph(i, j, maps, f));
			i++;
		}
		j++;
	}
	mlx_key_hook(f->window, on_key_press, f);
	mlx_scroll_hook(f->window, on_scroll, f);
	mlx_loop(f->window);
}
