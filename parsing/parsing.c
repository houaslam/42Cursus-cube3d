/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/30 07:36:19 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(t_map *map, char **av)
{
	int	start;

	read_map(&map, av);
	s_directions_initialization(ma)
	cardinal_directions(&map);
	player_position(&map);
	map_dimension(&map);
	// open_map(map);
	int	i = 0;
	while (map->map[i])
	{
		printf("[%s]\n", map->map[i]);
		i++;
	}
}
