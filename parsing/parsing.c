/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/21 14:27:34 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parsing(t_map **map, char **av)
{
	(void)av;

	(*map)->map = (char **)malloc(sizeof(char *) * 7);
	(*map)->map[0] = "11111";
	(*map)->map[1] = "10001";
	(*map)->map[2] = "10001";
	(*map)->map[3] = "1N001";
	(*map)->map[4] = "10001";
	(*map)->map[5] = "11111";
	(*map)->map[6] = NULL;
	// read_map(map);
	// map_dimension(map);
	player_position(map);
}
