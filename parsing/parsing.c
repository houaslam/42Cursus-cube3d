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

void	put_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	str_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	s_directions_initialization(t_map **map)
{
	(*map)->directions->f = NULL;
	(*map)->directions->c = NULL;
	(*map)->directions->ea = NULL;
	(*map)->directions->we = NULL;
	(*map)->directions->no = NULL;
	(*map)->directions->so = NULL;
}

void	fill_new_map(t_map **map, int s)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * ((*map)->m_y + 100));
	while ((*map)->map[s])
	{
		new[i] = ft_strdup((*map)->map[s]);
		s++;
		i++;
	}
	new[i] = NULL;
	ft_free((*map)->map);
	(*map)->map = new;
	// (*map)->map = new;//// NEW
}

void	parsing(t_map *map, char **av)
{
	int	s;

	s = 0;
	read_map(&map, av);
	s_directions_initialization(&map);
	cardinal_directions(&map, &s);
	player_position(&map, s);
	map_dimension(&map, s);
	////fill with the new map starting with s == after
	fill_new_map(&map, s);
	map_parsing(&map);
	int	i = 0;
	while (map->map[i])
	{
		printf("[%s]\n", map->map[i]);
		i++;
	}
	printf("%d | %d\n", i, map->m_y);
	// open_map(map);
}
