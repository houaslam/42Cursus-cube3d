/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/21 15:41:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	quadrant(t_map **map)
{
	if ((*map)->r.cast >= 360)
		(*map)->r.cast -= 360;
	else if ((*map)->r.cast < 0)
		(*map)->r.cast += 360;
	if (0 <= (*map)->r.cast && (*map)->r.cast < 90)
		case_one(map);
	else if (90 < (*map)->r.cast && (*map)->r.cast < 180)
		case_two(map);
	else if (180 < (*map)->r.cast && (*map)->r.cast < 270)
		case_three(map);
	else if (270 < (*map)->r.cast && (*map)->r.cast < 360)
		case_four(map);
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
	return (0);
}

void	case_one(t_map **map)
{
	static int i;

	(*map)->r.alpha = (*map)->r.cast;

	(*map)->h.cy = (((int)(*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (*map)->p.u_x + (((*map)->p.u_y - (*map)->h.cy) / tan((*map)->r.alpha * (M_PI / 180)));

	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) + UNIT;
	(*map)->v.cy = tan((*map)->r.alpha * (M_PI / 180)) * ((*map)->p.u_x- (*map)->v.cx) + (*map)->p.u_y;
	
	if (i == 0)
	{
		(*map)->h.dy = - UNIT;
		(*map)->h.dx = UNIT / tan((*map)->r.alpha * (M_PI / 180));
		
		(*map)->v.dx = UNIT;
		(*map)->v.dy = -UNIT * tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
}

void	case_two(t_map **map)
{
	static int i;
	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;

	(*map)->h.cy = ((int)((*map)->p.u_y / UNIT) * UNIT) - 1;
	(*map)->h.cx = (*map)->p.u_x - (((*map)->p.u_y - (*map)->h.cy) * tan((*map)->r.alpha * (M_PI / 180)));

	(*map)->v.cx = ((int)((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = (*map)->p.u_y - (((*map)->p.u_x - (*map)->v.cx) / tan((*map)->r.alpha * (M_PI / 180)));
	printf("v X = %d Y = %d\n", (*map)->v.cx / 64, (*map)->v.cy / 64);
	printf("h X = %d Y = %d\n", (*map)->h.cx / 64, (*map)->h.cy / 64);
	if (i == 0)
	{
		(*map)->h.dy = -UNIT;
		(*map)->h.dx = -UNIT * tan((*map)->r.alpha * (M_PI / 180));
	
		(*map)->v.dx = -UNIT;
		(*map)->v.dy = -UNIT / tan((*map)->r.alpha * (M_PI / 180));
		i++;
	}
	exit(0);
}

void	case_three(t_map **map)
{
	static int i;

	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;

	(*map)->h.cy = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) / tan((*map)->r.alpha)) + (*map)->p.u_x;


	(*map)->v.cx = (floor((*map)->p.u_x / UNIT) * UNIT) - 1;
	(*map)->v.cy = tan((*map)->r.alpha) * ((*map)->p.u_x - (*map)->v.cx) + (*map)->p.u_y;

	if (i == 0)
	{
		(*map)->h.dy = UNIT;
		(*map)->h.dx = - UNIT * tan((*map)->r.alpha);
		(*map)->v.dx = -UNIT;
		(*map)->v.dy = UNIT * tan((*map)->r.alpha);
		i++;
	}
}

void	case_four(t_map **map)
{
	static int i;

	(*map)->r.alpha = (*map)->r.cast - (*map)->r.ang;

	(*map)->h.cy = (floor((*map)->p.u_y / UNIT) * UNIT) + UNIT;
	(*map)->h.cx = (((*map)->h.cy - (*map)->p.u_y) * tan((*map)->r.alpha)) + (*map)->p.u_x;


	(*map)->v.cx = (floor((*map)->p.u_x / UNIT) * UNIT) - UNIT;
	(*map)->v.cy = ((*map)->p.u_x - (*map)->v.cx) / tan((*map)->r.alpha) + (*map)->p.u_y;

	if (i == 0)
	{
		(*map)->h.dy = UNIT;
		(*map)->h.dx = UNIT * tan((*map)->r.alpha);
		(*map)->v.dx = UNIT;
		(*map)->v.dy = UNIT / tan((*map)->r.alpha);
		i++;
	}
}
