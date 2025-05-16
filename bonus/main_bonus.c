/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/08 23:37:06 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	creat_phoenix(double cr, double ci, double pr, double pi)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractalp	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Phoenix Fractal", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	mlx_image_to_window(window, image, 0, 0);
	creat_contun_phen(&fractal, window, image);
	fractal.cr = cr;
	fractal.ci = ci;
	fractal.pr = pr;
	fractal.pi = pi;
	fractal.col = malloc(sizeof(t_coler));
	if (!fractal.col) 
	{
		fractal.col = NULL;
		mlx_terminate(window);
		return ;
	}
	fractal.col->i = 1;
	fractal.col->max_iter = MAX_ITER;
	phoenix(&fractal);
	mlx_terminate(window);
	free(fractal.col);
}

void	creat_julia(double a, double b)
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_fractalj	fractal;

	window = mlx_init(WIDTH, HEIGHT, "Julia", false);
	image = mlx_new_image(window, WIDTH, HEIGHT);
	mlx_image_to_window(window, image, 0, 0);
	fractal.window = window;
	fractal.image = image;
	creat_contun_julia(&fractal);
	fractal.a = a;
	fractal.b = b;
	fractal.col = malloc(sizeof(t_coler));
	if (!fractal.col) 
	{
		fractal.col = NULL;
		mlx_terminate(window);
		return ;
	}
	fractal.col->i = 1;
	fractal.col->max_iter = MAX_ITER;
	julia(&fractal);
	mlx_terminate(window);
	free(fractal.col);
}

int	handle_julia(char **argv)
{
	int	f;

	if (check_dots(argv[2]) && check_dots(argv[3]))
	{
		f = main_jul(argv[2], argv[3]);
		if (f == 1)
			exit(1);
	}
	else
		return (write(2, "Julia <a> <b> between 2 & -2\n", 29), 1);
	return (0);
}

int	handle_phoenix(char **argv)
{
	int	f;

	if (check_dots(argv[2]) && check_dots(argv[3]) 
		&& check_dots(argv[4]) && check_dots(argv[5]))
	{
		f = main_phen(argv[2], argv[3], argv[4], argv[5]);
		if (f == 1)
			exit(1);
	}
	else
		return (write(2, USE_MSG1, 44), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strcomp(argv[1], "Mandelbrot") == 1)
	{
		creat_mand();
		return (0);
	}
	else if (argc == 4 && ft_strcomp(argv[1], "Julia") == 1)
		return (handle_julia(argv));
	else if (argc == 6 && ft_strcomp(argv[1], "Phoenix") == 1)
		return (handle_phoenix(argv));
	else
		return (write(2, USE_MSG2, 70), 1);
}
