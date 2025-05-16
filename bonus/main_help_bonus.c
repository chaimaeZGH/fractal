/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/08 23:23:35 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main_jul(char *s1, char *s2)
{
	double	a;
	double	b;

	a = ft_atoif(s1);
	b = ft_atoif(s2);
	if (a >= -2.0 && a <= 2.0 && b >= -2.0 && b <= 2.0)
	{
		creat_julia(a, b);
		return (0);
	}
	else
		return (write(0, "<a> or <b> incorect\n", 20), 1);
}

int	main_phen(char *s1, char *s2, char *s3, char *s4)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = ft_atoif(s1);
	b = ft_atoif(s2);
	c = ft_atoif(s3);
	d = ft_atoif(s4);
	if (a >= -2.0 && a <= 2.0 && b >= -2.0 && b <= 2.0 && 
		c >= -2.0 && c <= 2.0 && d >= -2.0 && d <= 2.0)
	{
		creat_phoenix(a, b, c, d);
		return (0);
	}
	else
		return (write(0, "invalid <a> <b> <c> <d>\n", 24), 1);
}

void	creat_contun_julia(t_fractalj *f)
{
	f->zoom_xmax = 1.0;
	f->zoom_xmin = 1.0; 
	f->zoom_ymax = 1.0;
	f->zoom_ymin = 1.0;
}

void	creat_contun_phen(t_fractalp *f, mlx_t *window, mlx_image_t *image)
{
	f->zoom_xmax = 1.0;
	f->zoom_xmin = 1.0; 
	f->zoom_ymax = 1.0;
	f->zoom_ymin = 1.0;
	f->window = window;
	f->image = image;
}

void	creat_contun_mandal(t_fractal *f)
{
	f->zoom_xmax = 1.0;
	f->zoom_xmin = 1.0; 
	f->zoom_ymax = 1.0;
	f->zoom_ymin = 1.0;
}
