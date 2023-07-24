/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/24 11:52:25 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	p_to_wall(t_map *map)
{
	int	x;
	int	y;
	int	h;
	int	v;

	x = map->p.u_x - map->h.cx;
	y = map->p.u_y - map->h.cy;
	if ((map)->r.cast <= 100.350800 && (map)->r.cast > 99)
		printf("H x = %d y = %d\n", x, y);
	h = sqrt(pow(x, 2) + pow(y, 2));
	y = map->p.u_y - map->v.cy;
	x = map->p.u_x - map->v.cx;
	if ((map)->r.cast <= 100.350800 && (map)->r.cast > 99)
		printf("V x = %d y = %d\n", x, y);
	v = sqrt(pow(x, 2) + pow(y, 2));
	if (map->n_v || h < v)
		return (h);
	if (map->n_h || h >= v)
	{
		if ((map)->r.cast <= 100.350800 && (map)->r.cast > 99)
		{
			printf("3for angle %f\n",(map)->r.cast);
			printf("0P (%d, %d)  h (%d, %d) v (%d, %d) \n", map->p.u_x,map->p.u_y, (map)->h.cx, (map)->h.cy, (map)->v.cx, (map)->v.cy);
			printf("4its v = %d but h = %d\n", v, h);
		}
		return (v);
	}
	return (0);
}

void	set_distance(t_map **map, t_window *window)
{
	int	i;

	i = 0;
	(*map)->p.u_x = ((*map)->p.x * UNIT) + (UNIT / 2);
	(*map)->p.u_y = ((*map)->p.y * UNIT) + (UNIT / 2);
	while (i < PP_WIDTH)
	{
		quadrant(map);
		(*map)->p_to_w = p_to_wall(*map);
		(*map)->wall_h = wall_height(*map);
		draw_ray(window, i);
		if ((*map)->r.cast <= 100.350800 && (*map)->r.cast > 99)
			printf("==============\n");
			// break;
		(*map)->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
}

// map->p_to_w *= cos(map->r.alpha); fish eye
int	wall_height(t_map *map)
{
	int	b;
	int	ret;

	b = (PP_WIDTH / 2) / tan((VIEW_D / 2) * (M_PI / 180));
	ret = (UNIT * b) / map->p_to_w;
	return (ret);
}
