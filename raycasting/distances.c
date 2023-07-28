/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:25:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/28 16:47:38 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_case_h(t_map *map)
{
	map->n_h = 1;
	if (map->h.y < 0 || map->h.x / UNIT >= map->m_x)
		return (0);
	if (map->h.x < 0 || map->h.y / UNIT >= map->m_y)
		return (0);
	map->n_h = 0;
	if (map->map[(int)map->h.y / UNIT][(int)map->h.x / UNIT] == '1')
		return (0);
	return (1);
}

int	check_case_v(t_map *map)
{
	map->n_v = 1;
	if (map->v.y < 0 || map->v.x / UNIT >= map->m_x)
		return (0);
	if (map->v.x / UNIT < 0 || map->v.y / UNIT >= map->m_y)
		return (0);
	map->n_v = 0;
	if (map->map[(int)map->v.y / UNIT][(int)map->v.x / UNIT] == '1')
		return (0);
	return (1);
}

float	p_to_wall(t_map *map)
{
	float	x;
	float	y;
	float	h;
	float	v;

	y = map->p.u_y - map->h.y;
	if (0 <= (map)->r.cast && (map)->r.cast <= 180)
		y = map->p.u_y - map->h.y++;
	x = map->p.u_x - map->h.x;
	h = sqrt(pow(x, 2) + pow(y, 2));
	y = map->p.u_y - map->v.y;
	x = map->p.u_x - map->v.x;
	if (90 <= (map)->r.cast && (map)->r.cast <= 270)
		x = map->p.u_x - map->v.x++;
	v = sqrt(pow(x, 2) + pow(y, 2));
	if (map->n_h || h >= v)
		return (v * cos((map->r.ang - map->r.cast) * M_PI / 180));
	return (h * cos((map->r.ang - map->r.cast) * M_PI / 180));
	return (0);
}

float	wall_height(t_map *map)
{
	double	b;
	double	ret;

	b = (PP_WIDTH / 2) / tan((VIEW_D / 2) * (M_PI / 180));
	ret = (UNIT * b) / map->p.to_w;
	return (ret);
}
