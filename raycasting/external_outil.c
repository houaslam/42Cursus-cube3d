/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_outil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:52:54 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 07:41:44 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_case_h(t_map **map)
{
	if (!((*map)->h.cx / UNIT < (*map)->m_x || (*map)->h.cx / UNIT >= 0))
	{
		(*map)->its_v = 1;
		(*map)->its_h = 0;
		printf("YEA\n");
		exit(0);
		return (0);
	}
	if (!((*map)->h.cy / UNIT < (*map)->m_y || (*map)->h.cy / UNIT >= 0))
	{
		(*map)->its_v = 1;
		(*map)->its_h = 0;
		printf("NO\n");
		exit(0);
		return (0);
	}
	if ((*map)->map[(int)(*map)->h.cy / UNIT][(int)(*map)->h.cx / UNIT] == '1')
		return (0);
	return (1);
}

int	check_case_v(t_map **map)
{
	printf("C_VY = %d\n", (*map)->v.cy);
	if ((*map)->v.cx / UNIT > (*map)->m_x || (*map)->v.cx / UNIT < 0)
	{
		(*map)->its_v = 0;
		(*map)->its_h = 1;
		exit(0);
		return (0);
	}
	if ((*map)->v.cy / UNIT > (*map)->m_y || (*map)->v.cy / UNIT < 0)
	{
		exit(0);
		(*map)->its_v = 0;
		(*map)->its_h = 1;
		return (0);
	}
	if ((*map)->map[(int)(*map)->v.cy / UNIT][(int)(*map)->v.cx / UNIT] == '1')
		return (0);
	return (1);
}
