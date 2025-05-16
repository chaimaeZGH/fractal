/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function_for_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:54 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/09 12:30:22 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	handle_franmej(t_fractalj *f, double x_step, double y_step)
{
	f->zoom_xmin += x_step * -2;
	f->zoom_xmax += x_step * 2;
	f->zoom_ymin += y_step * -2;
	f->zoom_ymax += y_step * 2;
}

void	handle_franmem(t_fractal *f, double x_step, double y_step)
{
	f->zoom_xmin += x_step * -2;
	f->zoom_xmax += x_step * 2;
	f->zoom_ymin += y_step * -2;
	f->zoom_ymax += y_step * 2;
}

void	handle_franmep(t_fractalp *f, double x_step, double y_step)
{
	f->zoom_xmin += x_step * -2;
	f->zoom_xmax += x_step * 2;
	f->zoom_ymin += y_step * -2;
	f->zoom_ymax += y_step * 2;
}
