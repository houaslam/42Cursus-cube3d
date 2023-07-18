/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/18 08:11:03 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	quadrant(t_map **map)
{
	if (0 < (*map)->r.ang && (*map)->r.ang < 90)
	{
		(*map)->r.up = 1;
		(*map)->r.right = 0;
	}
	else if (91 <= (*map)->r.ang && (*map)->r.ang <= 179)
	{
		(*map)->r.up = 1;
		(*map)->r.left = 1;
	}
	else if (181 <= (*map)->r.ang && (*map)->r.ang <= 179)
	{
		(*map)->r.down = 1;
		(*map)->r.left = 1;
	}
	else if (271 <= (*map)->r.ang && (*map)->r.ang <= 359)
	{
		(*map)->r.down = 1;
		(*map)->r.right = 1;
	}
}

// void	quadrant_1(t_map **map)
// {
// 	int	dx;
// 	int	dy;

// 	(*map)->c_hy = (floor((*map)->pu_y / UNIT) * UNIT) - 1;
// 	(*map)->c_hx = (((*map)->pu_y - (*map)->c_hy) \
// 	/ tan((*map)->alpha)) + (*map)->pu_x;
// 	dx = UNIT / tan((*map)->alpha);
// 	dy = -UNIT;
// 	while (check_case(map))
// 	{
// 		(*map)->c_hx += dx;
// 		(*map)->c_hy += dy;
// 	}
// }

// void	quadrant_2(t_map **map)
// {
// 	int	dx;
// 	int	dy;

// 	(*map)->alpha = ((*map)->r.ang - 90) * (M_PI / 180);
// 	(*map)->c_hy = ((floor((*map)->pu_y / UNIT)) * UNIT) - 1;
// 	(*map)->c_hx = (int)(tan((*map)->alpha) / ((*map)->c_hy - (*map)->pu_y)) + (*map)->pu_x;
// 	dx = -UNIT / tan((*map)->alpha);
// 	dy = -UNIT;
// 	while (check_case(map))
// 	{
// 		(*map)->c_hx += dx;
// 		(*map)->c_hy += dy;
// 	}
// }

// void	quadrant_3(t_map **map)
// {
// 	int	dx;
// 	int	dy;

// 	(*map)->alpha = ((*map)->r.ang - 180) * M_PI / 180;
// 	(*map)->pu_x = (*map)->p_x * UNIT + (UNIT / 2);
// 	(*map)->pu_y = (*map)->p_y * UNIT + (UNIT / 2);
// 	(*map)->c_hy = (((*map)->pu_y / UNIT) * UNIT) + 64;
// 	(*map)->c_hx = (*map)->pu_x - ((*map)->c_hy - (*map)->pu_y) / tan((*map)->alpha);
// 	dx = -UNIT * tan((*map)->alpha);
// 	dy = UNIT;
// 	while (check_case(map))
// 	{
// 		(*map)->c_hx += dx;
// 		(*map)->c_hy += dy;
// 	}
// }

// void	quadrant_4(t_map **map)
// {
// 	int	dx;
// 	int	dy;

// 	(*map)->alpha = (*map)->r.ang - 270 * M_PI / 180;
// 	(*map)->pu_x = (*map)->p_x * UNIT + (UNIT / 2);
// 	(*map)->pu_y = (*map)->p_y * UNIT + (UNIT / 2);
// 	(*map)->c_hy = (((*map)->pu_y / UNIT) * UNIT) + 64;
// 	(*map)->c_hx = (*map)->pu_x + tan((*map)->alpha) * ((*map)->c_hy - (*map)->pu_y);
// 	dx = UNIT / tan((*map)->alpha);
// 	dy = UNIT;
// 	while (check_case(map))
// 	{
// 		(*map)->c_hx += dx;
// 		(*map)->c_hy += dy;
// 	}
// }

// void horizental_inter(t_map **map)
// {
// 	int	x;
// 	int y;

// 	(*map)->c_hy = floor((*map)->pu_y / 64) * 64;
// 	// if ((*map)->r.ang > 0 && (*map)->r.ang < 180)
// 	(*map)->c_hy -= 1;
// 	// else
// 	// (*map)->c_hy += 64;
// 	(*map)->c_hx = (tan((*map)->alpha) * ((*map)->c_hy - (*map)->p_y)) + (*map)->p_x;
// 	y = -UNIT;
// 	x = y / tan((*map)->alpha);
// 	while (check_case(map))
// 	{
// 		(*map)->c_hx += x;
// 		(*map)->c_hy += y;
// 	}
// 	// if ((*map)->r.ang > 90 && (*map)->r.ang < 270)
// 	// 	(*map)->c_hx -= 1;
// 	// else
// 	// 	(*map)->c_hy += 64;
// }

