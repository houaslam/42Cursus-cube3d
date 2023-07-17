/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/17 10:18:01 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'E')
		(*map)->ray_ang = 60;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'N')
		(*map)->ray_ang = 120;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'W')
		(*map)->ray_ang = 210;
	else if ((*map)->map[(int)(*map)->p_y][(int)(*map)->p_x] == 'S')
		(*map)->ray_ang = 300;
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}
