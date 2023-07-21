/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/21 18:12:05 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void parsing(t_map **map, char **av)
{
	read_map(map, av);
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
