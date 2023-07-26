/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/26 13:53:49 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


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
		(*map)->p.to_w = p_to_wall(*map) * cos(((*map)->r.ang - (*map)->r.cast) * M_PI / 180);
		// printf("pto_wall = [%d] cos = [%f]\n", p_to_wall(*map), cos(((*map)->r.ang - (*map)->r.cast) * M_PI / 180)));
		printf("and = %f  cast = %f\n", (*map)->r.ang, (*map)->r.cast);
		// printf("res = [%d]\n", (*map)->p.to_w);
		(*map)->wall_h = wall_height(*map);
		draw_ray(window, i);
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, (*map)->img.img, 0, 0);
    draw_minimap(*map);
}
