/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 15:35:24 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rays_casting(t_map **map, t_window *window)
{
	int	i;

	i = 0;
    (void)window;
	(*map)->r.cast = (*map)->r.ang + 30;
	while (i < PP_WIDTH)
	{
        (*map)->n_v = 0;
	    (*map)->n_h = 0;
		quadrant(map);
		(*map)->p.to_w = p_to_wall(*map);
		(*map)->wall_h= wall_height(*map);
        printf("WALL = %d\n", (*map)->wall_h);
        printf("to wall = %d\n", (*map)->p.to_w);
		draw_ray(window, i);
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
    draw_minimap(*map);
}
