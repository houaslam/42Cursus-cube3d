/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 17:46:11 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rays_casting(t_map **map, t_window *window)
{
	int	i;

	i = 0;
    // (void)window;
	(*map)->r.cast = (*map)->r.ang + 30;
	(*map)->img.addr = mlx_get_data_addr((*map)->img.img, \
	&(*map)->img.bits_per_pixel, &(*map)->img.line_length, &(*map)->img.endian);
	while (i < PP_WIDTH)
	{
        (*map)->n_v = 0;
	    (*map)->n_h = 0;
		quadrant(map);
		(*map)->p.to_w = p_to_wall(*map);
		(*map)->wall_h= wall_height(*map);
		draw_ray(window, i);
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, (*map)->img.img, 0, 0);
    // draw_minimap(*map);
}
