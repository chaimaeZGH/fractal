/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:50 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/08 23:24:44 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> 
# include "../MLX42/include/MLX42/MLX42.h"
# define MAX_ITER 1000
# define WIDTH 800
# define HEIGHT 800
# define USE_MSG1 "Phoenix args <a> <b> <c> <d> between 2 & -2\n"
# define USE_MSG2 "Phoenix <a> <b> <c> <d> or Mandelbrot or Julia <a> <b> \
					 between 2 & -2\n"

typedef struct s_coler
{
	int	iter;
	int	max_iter;
	int	i;
}	t_coler;

typedef struct s_fractal
{
	double		zoom_xmin;
	double		zoom_xmax;
	double		zoom_ymin;
	double		zoom_ymax;
	int			x_pos;
	int			y_pos;
	mlx_t		*window;
	mlx_image_t	*image;
	t_coler		*col;
}	t_fractal;

typedef struct s_fractalj
{
	double		zoom_xmin;
	double		zoom_xmax;
	double		zoom_ymin;
	double		zoom_ymax;
	mlx_t		*window;
	mlx_image_t	*image;
	int			x_pos;
	int			y_pos;
	double		a;
	double		b;
	t_coler		*col;
}	t_fractalj;

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
	int			x_pos;
	int			y_pos;
	t_coler		*col;
}	t_fractalp;

typedef struct s_map
{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}	t_map;

long	get_color(t_coler *col);
void	mandelbrot(t_fractal *f);
int		check_dots(char *s);
void	julia(t_fractalj *f);
double	ft_parse_decimal(char *str, int *i, double result, double *f);
double	ft_atoif(char *str);
int		phoenix_iter(double zr, double zi, t_fractalp *f);
void	phoenix(t_fractalp *f);
int		ft_strcomp(char *s1, char *s2);
double	map(t_map a, int value);
void	creat_julia(double a, double b);
void	creat_mand(void);
void	creat_phoenix(double cr, double ci, double pr, double pi);
int		julia_iter(double zr, double zi, double cr, double ci);
int		mandelbrot_iter(double cr, double ci);
void	handle_franmej(t_fractalj *f, double x_step, double y_step);
void	handle_franmem(t_fractal *f, double x_step, double y_step);
void	handle_franmep(t_fractalp *f, double x_step, double y_step);
void	creat_contun_mandal(t_fractal *f);
void	creat_contun_julia(t_fractalj *f);
void	creat_contun_phen(t_fractalp *f, mlx_t *window, mlx_image_t *image);
int		main_jul(char *s1, char *s2);
int		main_phen(char *s1, char *s2, char *s3, char *s4);

#endif