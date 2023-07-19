/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 08:04:34 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'E')
		(*map)->r.ang = 0;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'N')
		(*map)->r.ang = 90;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'W')
		(*map)->r.ang = 180;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'S')
		(*map)->r.ang = 270;
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}
