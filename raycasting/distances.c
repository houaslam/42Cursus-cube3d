/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/23 11:09:34 by houaslam         ###   ########.fr       */
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
	if (map->n_v || h <= v)
	{
		// if (map->r.cast > 90)
			// printf("h WALL = %d\n", h);
		return (h);
	}
	else
	{
		// if (map->r.cast > 90)
			// printf("v WALL = %d\n", v);
		return (v);
	}
}

void	set_distance(t_map **map, t_window *window)
{
	int	i;

	i = 0;
	(void)window;
	(*map)->p.u_x = (*map)->p.x * UNIT + (UNIT / 2);
	(*map)->p.u_y = (*map)->p.y * UNIT + (UNIT / 2);
	while (i < PP_WIDTH)
	{
		// if ((*map)->r.cast < 90)
		// {
		// 	break;
		// }
		// printf("CAST %f\n", (*map)->r.cast);
		quadrant(map);
		(*map)->p_to_w = p_to_wall(*map);
		(*map)->wall_h = wall_height(*map);
		draw_ray(window, i);
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
			// printf("h (%d,%d)\n", (*map)->h.cx / UNIT, (*map)->h.cy/ UNIT);
			// printf("v (%d,%d)\n", (*map)->v.cx / UNIT, (*map)->v.cy/ UNIT);
}

// map->p_to_w *= cos(map->r.alpha); fish eye
int	wall_height(t_map *map)
{
	int	b;
	int	ret;

	b = (PP_WIDTH / 2) / (tan((VIEW_D / 2) * (M_PI / 180)));
	ret = (UNIT * b) / map->p_to_w;
	return (ret);
}
