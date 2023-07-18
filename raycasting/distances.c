/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/18 08:14:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	horizental_inter(t_map **map)
{
	(*map)->h.cy = (floor((*map)->pu_y / UNIT) * UNIT);
	if ((*map)->r.up)
		(*map)->h.cy += 64;
	else
		(*map)->r.cy -= 1;
	(*map)->h.cx = ((*map)->h.cy - (*map)->p_y) \
	/ (tan((*map)->r.alpha)) + (*map)->p_x;
	printf("H CX = %d CY = %d\n", (*map)->h.cx / 64, (*map)->h.cy / 64);
	while (check_case_h(map))
	{
		(*map)->h.cx += (*map)->h.dx;
		(*map)->h.cy += (*map)->h.dy;
	}
}

void	vertical_inter(t_map **map)
{
	(*map)->v.cx = (floor((*map)->pu_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = (*map)->pu_y + ((*map)->pu_x \
	- (*map)->v.cx) * tan((*map)->r.alpha);
	while (check_case_v(map))
	{
		printf("V CX = %d CY = %d\n", (*map)->v.cx / 64, (*map)->v.cy / 64);
		(*map)->v.cx += (*map)->v.dx;
		(*map)->v.cy += (*map)->v.dy;
	}
}

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
	if (h >= v)
		return (v);
	return (h);
}

void	set_distance(t_map *map, t_window *window)
{
	int	i;

	i = 0;
	map->r.alpha = (map->r.ang - 90);
	map->pu_x = map->p_x * UNIT + (UNIT / 2);
	map->pu_y = map->p_y * UNIT + (UNIT / 2);
	map->h.dy = -UNIT;
	map->h.dx = map->h.dy * tan(map->r.alpha * (M_PI / 180));
	map->v.dx = -UNIT;
	map->v.dy = map->v.dx / tan(map->r.alpha * (M_PI / 180));
	while (i < PP_WIDTH / 2)
	{
		map->r.alpha = (map->r.ang - 90) * (M_PI / 180);
		horizental_inter(&map);
		vertical_inter(&map);
		map->p_to_w = p_to_wall(map);
		draw_ray(window, i);
		map->r.ang -= (float)VIEW_D / PP_WIDTH;
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
