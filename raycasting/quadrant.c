/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/08/03 09:48:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	find_wall(t_map *map)
{
	while (check_case_h(map))
	{
		map->h.x += map->h.step_x;
		map->h.y += map->h.step_y;
	}
	while (check_case_v(map))
	{
		map->v.x += map->v.step_x;
		map->v.y += map->v.step_y;
	}
}

void	initialize(t_map *map, int ray_to_cast)
{
	map->r.up = 0;
	map->r.left = 0;
	map->n_v = 0;
	map->n_h = 0;
	if (0 <= ray_to_cast && ray_to_cast <= 180)
		map->r.up = 1;
	if (90 <= ray_to_cast && ray_to_cast <= 270)
		map->r.left = 1;
	map->h.y = (floor(map->p.u_y / UNIT) * UNIT) + (!map->r.up) * UNIT;
	map->v.x = (floor(map->p.u_x / UNIT) * UNIT) + (!map->r.left) * UNIT;
	map->h.step_y = UNIT * (map->r.up * (-2) + 1);
	map->v.step_x = UNIT * (map->r.left * (-2) + 1);
	map->v.step_y = UNIT * (map->r.up * (-2) + 1);
	map->h.step_x = UNIT * (map->r.left * (-2) + 1);
}

void	execute(t_map *map)
{
	if ((map->r.up && !map->r.left) || (!map->r.up && map->r.left))
	{
		map->h.x = map->p.u_x + ((map->p.u_y - map->h.y) / tan(map->r.alpha));
		map->v.y = tan(map->r.alpha) * (map->p.u_x - map->v.x) + map->p.u_y;
		map->h.step_x /= tan(map->r.alpha);
		map->v.step_y *= tan(map->r.alpha);
	}
	else if ((map->r.up && map->r.left) || (!map->r.up && !map->r.left))
	{
		map->h.x = map->p.u_x - ((map->p.u_y - map->h.y) * tan(map->r.alpha));
		map->v.y = map->p.u_y - ((map->p.u_x - map->v.x) / tan(map->r.alpha));
		map->h.step_x *= tan(map->r.alpha);
		map->v.step_y /= (tan(map->r.alpha));
	}
}

void	quadrant(t_map *map, int ray_to_cast)
{
	initialize(map, ray_to_cast);
	map->r.alpha = (ray_to_cast - (int)(ray_to_cast / 90) * 90) * M_PI / 180;
	execute(map);
	find_wall(map);
}
