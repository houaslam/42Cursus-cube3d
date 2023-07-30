/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/30 07:39:34 by houaslam         ###   ########.fr       */
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

void	check_player(int s)
{
	if (!s)
	{
		printf("∆  we need a player here!");
		exit(0);
	}
	if (s > 1)
	{
		printf("∆  there is more than one player!");
		exit(0);
	}
}

void	player_position(t_map **map)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	(*map)->m_x = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if (ft_player(*map, i, j))
				s++;
			// if ((*map)->m_x < j)
			// 	(*map)->m_x = j;////doesnt hold the longest lenght
			j++;
		}
		if ((int)ft_strlen((*map)->map[i]) > (*map)->m_x)
			(*map)->m_x = ft_strlen((*map)->map[i]) + 1;
		i++;
	}
	(*map)->m_y = i;
	check_player(s);
}
