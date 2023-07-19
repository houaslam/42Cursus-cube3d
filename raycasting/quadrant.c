/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 09:44:22 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	quadrant(t_map **map)
{
	if (0 <= (*map)->r.ang && (*map)->r.ang < 90)
		case_one(map);
	else if (91 <= (*map)->r.ang && (*map)->r.ang <= 179)
		case_two(map);
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
	printf("%f h_cy : %d h_cx : %d v_cx : %d v_cy : %d\n", (*map)->r.alpha, (*map)->h.cy / 64, (*map)->h.cx / 64, (*map)->v.cx / 64, (*map)->v.cy / 64);
	return (0);
	}

// int	quadrant(t_map **map)
// {
// 	(*map)->r.up = 0;
// 	(*map)->r.down = 0;
// 	(*map)->r.right = 0;
// 	(*map)->r.left = 0;
// 	if (0 < (*map)->r.ang && (*map)->r.ang < 90)
// 	{
// 		printf("FOR ANG = %f\n", (*map)->r.ang);
// 		printf("H CX %d CY %d\n", (*map)->h.cx/ 64, (*map)->h.cy / 64);
// 		printf("H DX %d DY %d\n", (*map)->h.dx/ 64, (*map)->h.dy / 64);
// 		printf("V CX %d CY %d\n", (*map)->v.cx/ 64, (*map)->v.cy / 64);
// 		printf("V DX %d DY %d\n", (*map)->v.dx/ 64, (*map)->v.dy / 64);
// 		(*map)->r.alpha = (*map)->r.ang * (M_PI / 180);
// 		(*map)->r.up = 1;
// 		(*map)->r.right = 1;
// 		return (1);
// 	}
// 	else if (91 <= (*map)->r.ang && (*map)->r.ang <= 179)
// 	{
// 		(*map)->r.alpha = ((*map)->r.ang - 90) * (M_PI / 180);
// 		(*map)->r.up = 1;
// 		(*map)->r.left = 1;
// 		return (2);
// 	}
// 	else if (181 <= (*map)->r.ang && (*map)->r.ang <= 179)
// 	{
// 		(*map)->r.alpha = ((*map)->r.ang - 180) * (M_PI / 180);
// 		(*map)->r.down = 1;
// 		(*map)->r.left = 1;
// 		return (3);
// 	}
// 	else if (271 <= (*map)->r.ang && (*map)->r.ang <= 359)
// 	{
// 		(*map)->r.alpha = ((*map)->r.ang - 270) * (M_PI / 180);
// 		(*map)->r.down = 1;
// 		(*map)->r.right = 1;
// 		return (4);
// 	}
// 	return (0);
// 	}

void	horizental_inter_d(t_map **map)
{
	// x
	(*map)->h.dx = UNIT;
	if ((*map)->r.left)
		(*map)->h.dx *= -1;
	if ((*map)->r.up)
		(*map)->h.dx *= tan((*map)->r.alpha);
	else if ((*map)->r.down)
		(*map)->h.dx /= tan((*map)->r.alpha);
		//y
	(*map)->h.dy = UNIT;
	if ((*map)->r.up)
		(*map)->h.dy *= -1;
	while (check_case_h(map))
	{
		(*map)->h.cx += (*map)->h.dx;
		(*map)->h.cy += (*map)->h.dy;
	}
}

void	horizental_inter_c(t_map **map)
{
	// y
	(*map)->h.cy = (floor((*map)->p.u_y / UNIT) * UNIT);
	if ((*map)->r.up)
		(*map)->h.cy += 64;
	else if ((*map)->r.down)
		(*map)->h.cy -= 1;
	// x
	(*map)->h.cx = abs((*map)->h.cy - (*map)->p.u_y);
	if (((*map)->r.right && (*map)->r.up) || ((*map)->r.left && (*map)->r.down))
		(*map)->h.cx /= tan((*map)->r.alpha);
	else if (((*map)->r.left && (*map)->r.down) \
	|| ((*map)->r.right && (*map)->r.up))
		(*map)->h.cx *= tan((*map)->r.alpha);
	(*map)->h.cx += (*map)->p.u_x;
}

void	vertical_inter_d(t_map **map)
{
	// x
	(*map)->v.dx = UNIT;
	if ((*map)->r.left)
		(*map)->v.dx *= -1;
	// y
	(*map)->v.dy = UNIT;
	if ((*map)->r.up)
		(*map)->v.dy *= -1;
	if (((*map)->r.right && (*map)->r.up) || ((*map)->r.left && (*map)->r.down))
		(*map)->v.dy *= tan((*map)->r.alpha);
	else if (((*map)->r.left && (*map)->r.down) \
	|| ((*map)->r.right && (*map)->r.up))
		(*map)->v.dy /= tan((*map)->r.alpha);
}

void	vertical_inter_c(t_map **map)
{
	// x
	(*map)->v.cx = (floor((*map)->p.u_y / UNIT) * UNIT);
	if ((*map)->r.right)
		(*map)->v.cx += 64;
	else if ((*map)->r.left)
		(*map)->v.cx -= 1;
	// y
	(*map)->v.cy = abs((*map)->p.u_x - (*map)->v.cy);
	if (((*map)->r.right && (*map)->r.up) || ((*map)->r.left && (*map)->r.down))
		(*map)->v.cy *= tan((*map)->r.alpha);
	else if (((*map)->r.left && (*map)->r.down) \
	|| ((*map)->r.right && (*map)->r.up))
		(*map)->v.cy /= tan((*map)->r.alpha);
	(*map)->v.cy += (*map)->p.u_y;
		while (check_case_h(map))
	{
		(*map)->v.cx += (*map)->v.dx;
		(*map)->v.cy += (*map)->v.dy;
	}
}
