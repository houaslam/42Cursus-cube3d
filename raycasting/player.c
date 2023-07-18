/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/18 08:05:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'E')
		(*map)->r.ang = 60;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'N')
		(*map)->r.ang = 120;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'W')
		(*map)->r.ang = 210;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'S')
		(*map)->r.ang = 300;
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}
