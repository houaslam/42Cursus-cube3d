/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/24 14:27:32 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	quadrant(t_map **map)
{
	check_angles(map);
	if (0 <= (*map)->r.cast && (*map)->r.cast < 90)
		up_right(map);
	else if (90 < (*map)->r.cast && (*map)->r.cast < 180)
		up_left(map);
	else if (180 < (*map)->r.cast && (*map)->r.cast < 270)
		down_right(map);
	else if (270 < (*map)->r.cast && (*map)->r.cast < 360)
		down_left(map);
	while (check_case_h(map))
	{
		(*map)->h.cx += (*map)->h.dx;
		(*map)->h.cy += (*map)->h.dy;
	}
	while (check_case_v(map))
	{
		(*map)->v.cx += (*map)->v.dx;
		(*map)->v.cy += (*map)->v.dy;
	}
}

void	up_right(t_map **map)
{
	static int	i;

	(*map)->r.alpha = (*map)->r.cast;
	(*map)->h.cy = (((int)(*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (*map)->p.u_x + (((*map)->h.cy - (*map)->p.u_y) \
	/ tan((*map)->r.alpha * (M_PI / 180)));
	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) + UNIT;
	(*map)->v.cy = tan((*map)->r.alpha * (M_PI / 180)) * \
	((*map)->p.u_x - (*map)->v.cx) + (*map)->p.u_y;
	if (i == 0)
	{
		(*map)->n_v = 0;
		(*map)->n_h = 0;
		(*map)->h.dy = -UNIT;
		(*map)->h.dx = UNIT / tan((*map)->r.alpha * (M_PI / 180));
		(*map)->v.dx = UNIT;
		(*map)->v.dy = -UNIT * tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
}

void	up_left(t_map **map)
{
	static int	i;

	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;
	(*map)->h.cy = ((int)((*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (*map)->p.u_x - (((*map)->p.u_y - (*map)->h.cy) \
	* tan((*map)->r.alpha * (M_PI / 180)));
	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = (*map)->p.u_y + (((*map)->p.u_x - (*map)->v.cx) \
	/ tan((*map)->r.alpha * (M_PI / 180)));
	if (i == 0)
	{
		(*map)->n_v = 0;
		(*map)->n_h = 0;
		(*map)->h.dy = (-UNIT);
		(*map)->h.dx = (-UNIT) * tan((*map)->r.alpha * (M_PI / 180));
		(*map)->v.dx = (-UNIT);
		(*map)->v.dy = (-UNIT) / (tan((*map)->r.alpha * (M_PI / 180)));
		i++;
	}
}

void	down_right(t_map **map)
{
	static int	i;

	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;
	(*map)->h.cy = ((int)((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) * tan((*map)->r.alpha * (M_PI / 180))) + (*map)->p.u_x;

	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = ((*map)->v.cx - (*map)->p.u_x)/ (tan((*map)->r.alpha * (M_PI / 180))) + (*map)->p.u_y;
	if (i == 0)
	{
		(*map)->n_v = 0;
		(*map)->n_h = 0;
		(*map)->h.dy = UNIT;
		(*map)->h.dx = -UNIT * tan((*map)->r.alpha * (M_PI / 180));
		(*map)->v.dx = -UNIT;
		(*map)->v.dy = UNIT * tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
}

void	down_left(t_map **map)
{
	static int	i;

	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;
	
	(*map)->h.cy = ((int)((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) * tan((*map)->r.alpha * (M_PI / 180))) + (*map)->p.u_x;
	
	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) - UNIT;
	(*map)->v.cy = ((*map)->p.u_x - (*map)->v.cx) / tan((*map)->r.alpha * (M_PI / 180)) + (*map)->p.u_y;
	
	if (i == 0)
	{
		(*map)->n_v = 0;
		(*map)->n_h = 0;
		(*map)->h.dy = UNIT;
		(*map)->h.dx = UNIT * tan((*map)->r.alpha * (M_PI / 180));
		(*map)->v.dx = UNIT;
		(*map)->v.dy = UNIT / tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
}
