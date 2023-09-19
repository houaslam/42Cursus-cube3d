
#include "parsing.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_is_valid(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' &&\
	c != 'E' && c != '0' && c != '1' && c != ' ')
		return (1);
	return (0);
}

int		ft_is_player(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' &&\
	c != 'E' && c != '0')
		return (1);
	return (0);
}

void	check_wall_sides(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	while(ft_is_space(map[i]))
		i--;
	if (map[i] != '1')
		put_error("MAP ISN'T SURROUNDED BY WALLS");
}

void	check_wall_inside(char **map, int	i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '\
	|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		put_error("MAP ISN'T SURROUNDED BY WALLS");
}

void	check_sides_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_is_player(map[i]))
			put_error("MAP ISN'T SURROUNDED BY WALLS");
		i++;
	}
}
void    map_parsing(t_map **map)
{
	int j;
	int i;

	i = 0;
	check_sides_wall((*map)->map[i]);
	while ((*map)->map[i])
	{
		check_wall_sides((*map)->map[i]);
		j = 0;
		while ((*map)->map[i][j])
		{
			if (!ft_is_player((*map)->map[i][j]))
				check_wall_inside((*map)->map, i, j);
			j++;
		}
		i++;
	}
	i--;
	check_sides_wall((*map)->map[i]);
}
