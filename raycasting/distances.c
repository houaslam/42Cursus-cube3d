/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 08:08:57 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	p_to_wall(t_map *map)
{
	int	a;
	int	c;
	int	h;
	int	v;

	a = map->h.cy - map->pu_y;
	c = map->h.cx - map->pu_x;
	h = sqrt(pow(a, 2) + pow(c, 2));
	a = map->v.cy - map->pu_y;
	c = map->v.cx - map->pu_x;
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
	(void)window;
	(*map)->pu_x = (*map)->p_x * UNIT + (UNIT / 2);
	(*map)->pu_y = (*map)->p_y * UNIT + (UNIT / 2);
	k = 0;
	// vertical_inter_d(map);
	// horizental_inter_d(map);
	while (i < PP_WIDTH)
	{
		printf("alpha : %f ang : %f\n", (*map)->r.alpha, (*map)->r.ang);
		quadrant(map);
		(*map)->p_to_w = p_to_wall(*map);
		printf("WALL = %d\n",(*map)->p_to_w  );
		draw_ray(window, i);
		(*map)->r.ang -= (float)VIEW_D / PP_WIDTH;
		break ;
		
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
