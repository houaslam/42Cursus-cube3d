
#include "parsing.h"

char	*ft_dup(char *str)
{
	char	*tmp;
	char	*tmp1;
	char	*ret;

	tmp1 = ft_strtrim(str, " ");
	tmp = ft_strtrim(tmp1, "\t");
	free(tmp1);
	ret = ft_strdup(tmp);
	free(tmp);
	return(ret);
}

char	**split_it(char *map)
{
	char	**spl;

	spl = NULL;
	spl = ft_split(map, '\t');
	// ft_free(spl);
	// return (spl);
	if (str_lenght(spl) == 1)
	{
		ft_free(spl);
	exit(1);
		spl = ft_split(map, ' ');
	}
	return(spl);
}

void	directions_compar(char **str, t_directions *dir, int *s, int i)
{
	if (!str[0])
		return ;
	if (!ft_strcmp(str[0], "NO") && str_lenght(str) == 2)
	{
		if (dir->no)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->no = ft_dup(str[1]);
	}
	else if (!ft_strcmp(str[0], "SO") && str_lenght(str) == 2)
	{
		if (dir->so)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->so = ft_dup(str[1]);
	}
	else if (!ft_strcmp(str[0], "WE") && str_lenght(str) == 2)
	{
		if (dir->we)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		dir->we = ft_dup(str[1]);
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
	exit(1);

}

//// [DONE]..fill directions with null and whenever it takes a value check if it has null first {split + lenght == 2}
//// [DONE]at the end before i start with map check if my struct has no nall
//// [DONE]don't forget to write "error\n" first
//// [DONE]what if we added a line that has str_lenght == 3
//// [DONE]wtb if we had tabs and spaces
//// [DONE]when i start with map start checkin '0' if it's surronded by space == error first/last line and colones
//// [DONE]check if map has another character !(0 && 1 && E && W && S && N)
//// [DONE]check empty line
//// [DONE]resize map
//// [DONE]m_y and m_x
//// check textures in parsing(strtrim(" " && "\t"))
//// RGB
//// I should free when there is an error
//// TEST this -> F    	220,100,0