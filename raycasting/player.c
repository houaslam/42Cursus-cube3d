/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/22 08:41:34 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'E')
		(*map)->r.ang = 0;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'N')
		(*map)->r.ang = 90;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'W')
		(*map)->r.ang = 180;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'S')
		(*map)->r.ang = 270;
	(*map)->r.cast = (*map)->r.ang + 30;
}
