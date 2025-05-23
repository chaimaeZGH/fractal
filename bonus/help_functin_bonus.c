/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:54 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/06 22:00:41 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <string.h>

long	get_color(t_coler *col)
{
	double	t;
	int		g;
	int		b;
	int		r;

	t = (double)col->iter / col->max_iter;
	r = (int)(8 * col->i * (1 - t) * 255);
	g = (int)(10 * col->i * (1 - t) * 255);
	b = (int)(20 * col->i * (1 - t) * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	check_dots(char *s)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == '.' || s[i] == '\t' || s[i] == ' ' 
				|| (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+'))
			return (0);
		if (s[i] == '.')
		{
			dot_count++;
			if (s[i + 1] == '\0')
				return (0);
		}
		i++;
	}
	if (dot_count <= 1)
		return (1);
	else
		return (0);
}

double	ft_parse_decimal(char *str, int *i, double result, double *f)
{
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		*f = *f * 10;
		(*i)++;
	}
	return (result);
}

double	ft_atoif(char *str)
{
	double	result;
	int		sign;
	int		i;
	double	f;

	result = -3;
	sign = 1;
	i = 0;
	f = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	if (str[i] >= '0' && str[i] <= '9')
		result = (str[i++] - '0');
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		result = ft_parse_decimal(str, &i, result, &f);
	return (sign * result / f);
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
