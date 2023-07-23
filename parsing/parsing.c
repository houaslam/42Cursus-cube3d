/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/23 11:25:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parsing(t_map **map, char **av)
{
	// read_map(map, av);
	(void)av;
	(*map)->map = (char **)malloc(sizeof(char *) * 6);
	(*map)->map[0] = "11111111111";
	(*map)->map[1] = "10000000001";
	(*map)->map[2] = "10000000001";
	(*map)->map[3] = "100000000N1";
	(*map)->map[4] = "11111111111";
	(*map)->map[5] = NULL;
	player_position(map);
	map_dimension(map);
	// int	i;
	// i = 0;
	// while ((*map)->map[i])
	// {
	// 	printf("%s\n", (*map)->map[i]);
	// 	i++;
	// }
}


