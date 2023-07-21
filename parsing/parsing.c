/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/21 10:42:52 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parsing(t_map **map, char **av)
{
	(void)av;

	(*map)->map = (char **)malloc(sizeof(char *) * 5);
	(*map)->map[0] = "111";
	(*map)->map[1] = "100E1";
	(*map)->map[2] = "10001";
	(*map)->map[3] = "11111";
	(*map)->map[4] = NULL;
	// read_map(map);
	player_position(map);
	map_dimension(map);
}
