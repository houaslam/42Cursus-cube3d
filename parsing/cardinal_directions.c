
#include "parsing.h"

char	**split_it(char *map)
{
	char	**spl;

	spl = NULL;
	spl = ft_split(map, '\t');
	if (str_lenght(spl) == 1)
	{
		ft_free(spl);
		spl = ft_split(map, ' ');
	}
	return(spl);
}

void	directions_compar(char **str, t_directions *dir, int *s, int i)
{
	if (!ft_strcmp(str[0], "NO") && str_lenght(str) == 2)
	{
		if (dir->no)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->no = ft_strdup(str[1]);
	}
	else if (!ft_strcmp(str[0], "SO") && str_lenght(str) == 2)
	{
		if (dir->so)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->so = ft_strdup(str[1]);
	}
	else if (!ft_strcmp(str[0], "WE") && str_lenght(str) == 2)
	{
		if (dir->we)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->we = ft_strdup(str[1]);
	}
	else
		ea_and_colors(str, dir, s, i);
}

void	cardinal_directions(t_map **map, int *s)
{
	int		i;
	char	**spl;

	i = 0;
	while ((*map)->map[i])
	{
		spl = split_it((*map)->map[i]);
		directions_compar(spl, (*map)->directions, s, i);
		ft_free(spl);
		i++;
	}
}

//// [DONE]..fill directions with null and whenever it takes a value check if it has null first {split + lenght == 2}
//// [DONE]at the end before i start with map check if my struct has no nall
//// [DONE]don't forget to write "error\n" first
//// [DONE]what if we added a line that has str_lenght == 3
//// when i start with map start checkin '0' if it's surronded by space == error
//// wtb if we had tabs and spaces