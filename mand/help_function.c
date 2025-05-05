/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:56 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/05 18:41:08 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	on_key_press(struct mlx_key_data key_data, void *param)
{
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(((t_fractal *)param)->window);
}

long	get_color(int iter, int max_iter)
{
	double	t;
	int		g;
	int		b;
	int		r;

	t = (double)iter / max_iter;
	r = (int)(8 * (1 - t) * 255);
	g = (int)(80 * (1 - t) * 255);
	b = (int)(800 * (1 - t) * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xAA);
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
