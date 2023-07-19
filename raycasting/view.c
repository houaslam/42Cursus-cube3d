/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:09:38 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 12:05:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	case_one(t_map **map)
{
	static int i;

	(*map)->r.alpha = (*map)->r.ang - 60;

	(*map)->h.cy = (((int)(*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (((*map)->p.u_y - (*map)->h.cy) / tan((*map)->r.alpha * (M_PI / 180))) + (*map)->p.u_x;

	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) + UNIT;
	(*map)->v.cy = (tan((*map)->r.alpha * (M_PI / 180)) * ((*map)->p.u_x - (*map)->v.cx)) + (*map)->p.u_y;
	
	if (i == 0)
	{
		(*map)->h.dx = UNIT / tan((*map)->r.alpha * (M_PI / 180));
		(*map)->h.dy = -UNIT;
		
		(*map)->v.dx = UNIT;
		(*map)->v.dy = - UNIT * tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
	
}

void	case_two(t_map **map)
{
	static int i;

	(*map)->r.alpha = (*map)->r.ang + 30;
	
	(*map)->h.cy = ((int)((*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (tan((*map)->r.alpha * (M_PI / 180)) * ((*map)->h.cy - (*map)->p.u_y)) + (*map)->p.u_x;

	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) - UNIT;
	(*map)->v.cy = ((*map)->v.cx - (*map)->p.u_x) / tan((*map)->r.alpha * (M_PI / 180)) + (*map)->p.u_y;
	if (i == 0)
	{
		(*map)->h.dy = -UNIT;
		(*map)->h.dx = - UNIT * tan((*map)->r.alpha);
		(*map)->v.dx = -UNIT;
		(*map)->v.dy = - UNIT / tan((*map)->r.alpha);
		i++;
	}

}

void	case_three(t_map **map)
{
	(*map)->h.cy = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) / tan((*map)->r.alpha)) + (*map)->p.u_x;

	(*map)->h.dy = UNIT;
	(*map)->h.dx = - UNIT * tan((*map)->r.alpha);

	(*map)->v.cx = (floor((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = tan((*map)->r.alpha) * ((*map)->p.u_x - (*map)->v.cx) + (*map)->p.u_y;

	(*map)->v.dx = -UNIT;
	(*map)->v.dy = UNIT * tan((*map)->r.alpha);
}

void	case_four(t_map **map)
{
	(*map)->h.cy = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) * tan((*map)->r.alpha)) + (*map)->p.u_x;

	(*map)->h.dy = UNIT;
	(*map)->h.dx = UNIT * tan((*map)->r.alpha);

	(*map)->v.cx = (floor((*map)->p.u_x / UNIT) * UNIT) - UNIT;
	(*map)->v.cy = ((*map)->p.u_x - (*map)->v.cx) / tan((*map)->r.alpha) + (*map)->p.u_y;

	(*map)->v.dx = UNIT;
	(*map)->v.dy = UNIT / tan((*map)->r.alpha);
}
