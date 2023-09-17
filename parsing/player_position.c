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

int	ft_player(t_map *map, int i, int j, int h)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
	|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		map->p.x = j;
		map->p.y = i - h;
		return (1);
	}
	return (0);
}

void	check_player(int s)
{
	if (!s)
		// return;
		put_error("∆  we need a player here!");
	if (s > 1)
		// return;	
		put_error("∆  there is more than one player!");
}

void	player_position(t_map **map, int i)
{
	int	j;
	int	h;
	int	s;

	s = 0;
	// i = 0;
	h = i;
	(*map)->m_x = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if (ft_player(*map, i, j, h))
				s++;
			// if ((*map)->m_x < j)
			// 	(*map)->m_x = j;////doesnt hold the longest lenght
			j++;
		}
		if ((int)ft_strlen((*map)->map[i]) > (*map)->m_x)
			(*map)->m_x = ft_strlen((*map)->map[i]) + 1;
		i++;
	}
	(*map)->m_y = i - h;
	// (*map)->m_y = i;
	// printf("i == %d | h == %d\n", i, h);
	// printf("%d\n", i);
	check_player(s);
}

void	check_cardinal(t_directions *dir)
{
	if (!dir->no)
		put_error("NORTH TEXTURE IS MISSING");
	if (!dir->so)
		put_error("SOUTH TEXTURE IS MISSING");
	if (!dir->we)
		put_error("WEST TEXTURE IS MISSING");
	if (!dir->ea)
		put_error("EAST TEXTURE IS MISSING");
	if (!dir->c)
		put_error("C COLOR IS MISSING");
	if (!dir->f)
		put_error("F COLOR IS MISSING");
}
