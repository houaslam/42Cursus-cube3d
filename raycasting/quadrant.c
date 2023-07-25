/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 15:35:51 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	quadrant(t_map **map)
{
	// check_angles(map);
	if (0 <= (*map)->r.cast && (*map)->r.cast < 90)
		up_right(map);
	else if (90 <= (*map)->r.cast && (*map)->r.cast < 180)
		up_left(map);
	else if (180 <= (*map)->r.cast && (*map)->r.cast < 270)
		down_right(map);
	else if (270 <= (*map)->r.cast && (*map)->r.cast < 360)
		down_left(map);
	while (check_case_h(map))
	{
		(*map)->h.x += (*map)->h.step_x;
		(*map)->h.y += (*map)->h.step_y;
	}
	while (check_case_v(map))
	{
		(*map)->v.x += (*map)->v.step_x;
		(*map)->v.y += (*map)->v.step_y;
	}
}

void	up_right(t_map **map)
{
	(*map)->r.alpha = (*map)->r.cast;
	(*map)->h.y = ((floor((*map)->p.u_y / UNIT)) * UNIT) - 1;
	(*map)->h.x = (*map)->p.u_x + (((*map)->p.u_y - (*map)->h.y) \
	/ tan((*map)->r.alpha * M_PI / 180));
	(*map)->v.x = (floor((*map)->p.u_x / UNIT) * UNIT) + UNIT;
	(*map)->v.y = tan((*map)->r.alpha * (M_PI / 180)) * \
	((*map)->p.u_x - (*map)->v.x) + (*map)->p.u_y;
	(*map)->h.step_y = -UNIT;
	(*map)->h.step_x = UNIT / tan((*map)->r.alpha * M_PI / 180);
	(*map)->v.step_x = UNIT;
	(*map)->v.step_y = -UNIT * tan((*map)->r.alpha * M_PI / 180);
}

void	up_left(t_map **map)
{
	(*map)->r.alpha = (*map)->r.cast - 90;
	(*map)->h.y = (floor((*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.x = (*map)->p.u_x - (((*map)->p.u_y - (*map)->h.y) \
	* tan((*map)->r.alpha * (M_PI / 180)));
	(*map)->v.x = (floor((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.y = (*map)->p.u_y - (((*map)->p.u_x - (*map)->v.x) \
	/ tan((*map)->r.alpha * (M_PI / 180)));
	(*map)->h.step_y = (-UNIT);
	(*map)->h.step_x = (-UNIT) * tan((*map)->r.alpha * (M_PI / 180));
	(*map)->v.step_x = (-UNIT);
	(*map)->v.step_y = (-UNIT) / (tan((*map)->r.alpha * (M_PI / 180)));
}

void	down_left(t_map **map)
{
	(*map)->r.alpha = (*map)->r.cast - 180;

	(*map)->h.y = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.x = (*map)->p.u_x - ((*map)->p.u_y - (*map)->h.y) / tan((*map)->r.alpha * M_PI / 180);

	(*map)->v.x = (floor((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.y = ((*map)->p.u_x - (*map)->v.x) * tan((*map)->r.alpha * M_PI / 180) + (*map)->p.u_y;
	(*map)->h.step_y = UNIT;
	(*map)->h.step_x = -UNIT / tan((*map)->r.alpha * M_PI / 180);
	(*map)->v.step_x = -UNIT;
	(*map)->v.step_y = UNIT * tan((*map)->r.alpha * M_PI / 180);
	printf("h (%d,%d) v (%d,%d)\n", (int)(*map)->h.x, (int)(*map)->h.y, (int)(*map)->v.x,  (int)(*map)->v.y);
}

void	down_right(t_map **map)
{
	(*map)->r.alpha = (*map)->r.cast - 270;
	(*map)->h.y = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.x = (((*map)->h.y - (*map)->p.u_y) * tan((*map)->r.alpha \
	* (M_PI / 180))) + (*map)->p.u_x;
	(*map)->v.x = (floor((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.y = ((*map)->v.x - (*map)->p.u_x) / (tan((*map)->r.alpha \
	* (M_PI / 180))) + (*map)->p.u_y;

	(*map)->h.step_y = UNIT;
	(*map)->h.step_x = -UNIT * tan((*map)->r.alpha * (M_PI / 180));
	(*map)->v.step_x = -UNIT;
	(*map)->v.step_y = UNIT * tan((*map)->r.alpha * (M_PI / 180));
}
