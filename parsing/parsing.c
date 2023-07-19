/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/19 12:33:12 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parsing(t_map **map, char **av)
{
	(void)av;

	(*map)->map = (char **)malloc(sizeof(char *) * 5);
	(*map)->map[0] = "11111";
	(*map)->map[1] = "100E1";
	(*map)->map[2] = "10001";
	(*map)->map[3] = "10001";
	(*map)->map[4] = NULL;
	// read_map(map);
	// map_dimension(map);
	player_position(map);
}
