/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:51 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/26 23:01:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(t_map a, int value)
{
	return ((value - a.old_min) * (a.new_max - a.new_min) 
		/ (a.old_max - a.old_min) + a.new_min);
}

int	ft_strcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}

void	creat_mand(void)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractal	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	mlx_image_to_window(window, image, 0, 0);
	fractal.zoom = 1.0;
	fractal.window = window;
	fractal.image = image;
	mandelbrot(&fractal);
	mlx_terminate(window);
}

void	creat_julia(double a, double b)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractalj	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Julia", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	mlx_image_to_window(window, image, 0, 0);
	fractal.zoom = 1.0;
	fractal.window = window;
	fractal.image = image;
	fractal.a = a;
	fractal.b = b;
	julia(&fractal);
	mlx_terminate(window);
}

int	main(int argc, char **argv)
{
	double	a;
	double	b;

	if (argc < 2)
		return (write(1, "<Mandelbrot> or <Julia> <a> <b>\n", 57), 0);
	if (argc == 2 && ft_strcomp(argv[1], "Mandelbrot") == 1)
		creat_mand();
	else if (argc == 4 && ft_strcomp(argv[1], "Julia") == 1)
	{
		if (check_dots(argv[2]) == 1 && check_dots(argv[3]) == 1)
		{
			a = ft_atoif(argv[2]);
			b = ft_atoif(argv[3]);
			if (a >= -2.0 && a <= 2.0 && b >= -2.0 && b <= 2.0)
				creat_julia(a, b);
			else
				return (write(0, "<a> or <b> incorect\n", 20), 1);
		}
		else
			return (write(0, "Julia <a> <b>\n", 14), 1);
	}
	else
		return (write(0, "Mandelbrot or Julia <a> <b>\n", 29), 1);
}
