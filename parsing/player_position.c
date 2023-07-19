/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/19 12:39:02 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_player(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
	|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		map->p.x = j;
		map->p.y = i;
		return (1);
	}
	return (0);
}

void	player_position(t_map **map)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if (ft_player(*map, i, j))
				s++;////no need if or..
			if ((*map)->m_x < j)
			j++;
		}
		i++;
	}
	if (s > 1)
	{
		printf("∆  there is more than one player! ∆\n");
		exit (1);
	}
	(*map)->m_x = j;
	(*map)->m_y = i;
}
