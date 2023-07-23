/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_outil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:52:54 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/22 17:44:18 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	check_angles(t_map **map)
{
	if ((*map)->r.cast >= 360)
		(*map)->r.cast -= 360;
	else if ((*map)->r.cast < 0)
		(*map)->r.cast += 360;
	if ((*map)->r.alpha >= 360)
		(*map)->r.alpha -= 360;
	else if ((*map)->r.alpha < 0)
		(*map)->r.alpha += 360;
}

int	check_case_h(t_map **map)
{
	if ((*map)->h.cx < 0 || (*map)->h.cy < 0)
	{
		(*map)->n_h = 1;
		return (0);
	}
	if ((*map)->h.cx / UNIT >= (*map)->m_x \
	|| (*map)->h.cy / UNIT >= (*map)->m_y)
	{
		(*map)->n_h = 1;
		return (0);
	}
	if ((*map)->map[(int)(*map)->h.cy / UNIT][(int)(*map)->h.cx / UNIT] == '1')
		return (0);
	return (1);
}

int	check_case_v(t_map **map)
{
	if ((*map)->v.cy < 0 || (*map)->v.cx < 0)
	{
		(*map)->n_v = 1;
		return (0);
	}
	if ((*map)->v.cx / UNIT >= (*map)->m_x \
	|| (*map)->v.cy / UNIT >= (*map)->m_y)
	{
		(*map)->n_v = 1;
		return (0);
	}
	if ((*map)->map[(int)(*map)->v.cy / UNIT][(int)(*map)->v.cx / UNIT] == '1')
		return (0);
	return (1);
}
