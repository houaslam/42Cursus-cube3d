/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 12:07:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	p_to_wall(t_map *map)
{
	int	a;
	int	c;
	int	h;
	int	v;

	a = map->h.cy - map->p.u_y;
	c = map->h.cx - map->p.u_x;
	h = sqrt(pow(a, 2) + pow(c, 2));
	a = map->v.cy - map->p.u_y;
	c = map->v.cx - map->p.u_x;
	v = sqrt(pow(a, 2) + pow(c, 2));
	if (map->its_h)
		return (h);
	if (map->its_v)
		return (h);
	if (h >= v)
		return (v);
	return (h);
}

void	set_distance(t_map **map, t_window *window)
{
	int	i;
	int k;

	i = 0;
	(*map)->p.u_x = (*map)->p.x * UNIT + (UNIT / 2);
	(*map)->p.u_y = (*map)->p.y * UNIT + (UNIT / 2);
	k = 0;
	while (i < PP_WIDTH)
	{
		quadrant(map);
		// printf("alpha : %f ang : %f\n", (*map)->r.alpha, (*map)->r.ang);
		(*map)->p_to_w = p_to_wall(*map);
		draw_ray(window, i);
		(*map)->r.ang -= (float)VIEW_D / PP_WIDTH;
		// break ;
		
		i++;
	}
}

int	wall_height(t_map *map)
{
	int	b;
	int	ret;

	map->p_to_w *= cos(map->r.alpha);
	b = 277;
	ret = (UNIT * b) / map->p_to_w;
	return (ret);
}
