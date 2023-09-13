
#include "parsing.h"

void	split_it(char *map)
{
	char	**spl;
	char	**spl1;
	
	spl = ft_split(map, ' ');
	spl1 = ft_split(spl, '\t');
	ft_free(spl);
	return(spl1);
}

void	cardinal_directions(t_map **map)
{
	int		i;
	char	**spl;

	i = 0;
	while (map->map[i])
	{
		spl = split_it(map->map[i]);
		if ()
		i++;
	}
}

// ..fill directions with null and whenever it takes a value check if it has null first {split + lenght == 2}
// at the end before i start with map check if my struct has no nall
// when i start with map start checkin '0' if it's surronded by space == error
// don't forget to write "error\n" first