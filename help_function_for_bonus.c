/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function_for_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:44:54 by czghoumi          #+#    #+#             */
/*   Updated: 2025/04/24 18:34:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void on_key_press(struct mlx_key_data key_data, void *param)
{
    t_fractalp *f;

    f = (t_fractalp *)param;
    printf("Key pressed: %d, Current color i: %d\n", key_data.key, f->col->i);
    if (key_data.key == MLX_KEY_ESCAPE) 
        mlx_close_window(f->window);
    
    if (key_data.key == 49) 
    {
		if (f->col->i < 20) 
		{
        	f->col->i++;
		}
        printf("Increased i to: %d\n", f->col->i);
        phoenix(f);
    }
    if (key_data.key == 50)
	{
        if (f->col->i > 1) 
            f->col->i--;
        printf("Decreased i to: %d\n", f->col->i);
        phoenix(f);
    }
}

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

void	setup_maps(t_map *x_map, t_map *y_map, t_fractalp *f)
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
