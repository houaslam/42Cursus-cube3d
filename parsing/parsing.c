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

void	affiche(t_directions *d)
{
	if (d->no)
		printf("NORTH = [%s]\n", d->no);
	if (d->ea)
		printf("EAST  = [%s]\n", d->ea);
	if (d->so)
		printf("SOUTH = [%s]\n", d->so);
	if (d->we)
		printf("WEST  = [%s]\n", d->we);
	if (d->f)
		printf("F     = [%s]\n", d->f);
	if (d->c)
		printf("C     = [%s]\n", d->c);
}

void	fill_new_map(t_map **map, int s)
{
	char	**new;
	int		i;

	i = 0;
	// printf("%")
	new = malloc(sizeof(char *) * ((*map)->m_y + 2));//// edit 100
	while ((*map)->map[s] && i < (*map)->m_y + 1)
	{
		new[i] = ft_strdup((*map)->map[s]);
		s++;
		i++;
	}
	new[i] = NULL;
	ft_free((*map)->map);
	(*map)->map = new;
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
	fill_new_map(&map, s);
	////fill with the new map starting with s == after
	map_parsing(&map);
	int	i = 0;
	while (map->map[i])
	{
		printf("[%s]\n", map->map[i]);
		i++;
	}
	printf("%d | %d\n", i, map->m_y);
	affiche(map->directions);
	// open_map(map);
}
