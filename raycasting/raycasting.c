/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/27 11:41:27 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	ft_exit(t_window *mlx)
{
	printf("GAME OVER !!");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	check_angles(t_map **map)
{
	if ((*map)->r.ang >= 360)
	{
		(*map)->r.ang -= 360;
		(*map)->r.cast = (*map)->r.ang + 30;
	}
	else if ((*map)->r.ang < 0)
	{
		(*map)->r.ang += 360;
		(*map)->r.cast = (*map)->r.ang + 30;
	}
	else if ((*map)->r.cast >= 360)
		(*map)->r.cast -= 360;
	else if ((*map)->r.cast < 0)
		(*map)->r.cast += 360;
}

void	rays_casting(t_map **map, t_window *window)
{
	int	i;

	i = 0;
	(*map)->r.cast = (*map)->r.ang + 30;
	(*map)->img.addr = mlx_get_data_addr((*map)->img.img, \
	&(*map)->img.bits_per_pixel, &(*map)->img.line_length, &(*map)->img.endian);
	while (i < PP_WIDTH)
	{
		check_angles(map);
		(*map)->n_v = 0;
		(*map)->n_h = 0;
		quadrant(map);
		(*map)->p.to_w = p_to_wall(*map);
		(*map)->wall_h = wall_height(*map);
		draw_ray(window, i);
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
	mlx_put_image_to_window(window->mlx, \
	window->mlx_win, (*map)->img.img, 0, 0);
	draw_minimap(*map);
}
