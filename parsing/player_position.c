/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/19 11:06:45 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	player_position(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if ((*map)->map[i][j] == 'N' || (*map)->map[i][j] == 'S' \
			|| (*map)->map[i][j] == 'E' || (*map)->map[i][j] == 'W')
			{
				(*map)->p.x = j;
				(*map)->p.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
