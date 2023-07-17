/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_outil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:52:54 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/17 11:57:46 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_case_h(t_map **map)
{
	if (!((*map)->h.cx / 64 < (*map)->m_x && (*map)->h.cx / 64 >= 0))
		return (0);
	if (!((*map)->h.cy / 64 < (*map)->m_y && (*map)->h.cy / 64 >= 0))
		return (0);
	if (!((*map)->map[(int)(*map)->h.cy / 64][(int)(*map)->h.cx / 64] != '1'))
		return (0);
	return (1);
}

int	check_case_v(t_map **map)
{
	if (!((*map)->v.cx / 64 < (*map)->m_x && (*map)->v.cx / 64 >= 0))
		return (0);
	if (!((*map)->v.cy / 64 < (*map)->m_y && (*map)->v.cy / 64 >= 0))
		return (0);
	if (!((*map)->map[(int)(*map)->v.cy / 64][(int)(*map)->v.cx / 64] != '1'))
		return (0);
	return (1);
}
