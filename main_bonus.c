/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/04/24 18:09:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	creat_phoenix(double cr, double ci, double pr, double pi)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractalp	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Phoenix Fractal", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	if (!image) 
	{
		printf("Image creation failed!\n");
		mlx_close_window(window);
    	exit(1);
	}
	mlx_image_to_window(window, image, 0, 0);
	fractal.zoom_xmax = 1.0;
	fractal.zoom_xmin = fractal.zoom_ymax = fractal.zoom_ymin = fractal.zoom_xmax;
	fractal.window = window;
	fractal.image = image;
	fractal.cr = cr;
	fractal.ci = ci;
	fractal.pr = pr;
	fractal.pi = pi;
	fractal.col = malloc(sizeof(t_coler));
    if (!fractal.col) 
	{
		fractal.col = NULL;
        mlx_terminate(window);
        return;
    }
	fractal.col->i = 1;
    fractal.col->max_iter = MAX_ITER;
	phoenix(&fractal);
	mlx_terminate(window);
	free(fractal.col);
}

int	main(int argc, char **argv)
{
	double	a;
	double	b;
	double	c;
	double	d;

	if (argc == 6 && ft_strcomp(argv[1], "Phoenix") == 1)
	{
		if (check_dots(argv[2]) == 1 && check_dots(argv[3]) == 1 && 
			check_dots(argv[4]) == 1 && check_dots(argv[5]) == 1)
		{
			a = ft_atoif(argv[2]);
			b = ft_atoif(argv[3]);
			c = ft_atoif(argv[4]);
			d = ft_atoif(argv[5]);
			if (a >= -2.0 && a <= 2.0 && b >= -2.0 && b <= 2.0 && 
				c >= -2.0 && c <= 2.0 && d >= -2.0 && d <= 2.0)
				creat_phoenix(a, b, c, d);
			else
				return (write(0, "invalid <a> <b> <c> <d>\n", 24), 1);
		}
		else
			return (write(0, "invalid <a> <b> <c> <d>\n", 24), 1);
	}
	else
		return (write(0, "Phoenix <a> <b> <c> <d>\n", 24), 1);
}
