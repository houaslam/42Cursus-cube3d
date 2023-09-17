
#include "parsing.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void    map_parsing(t_map **map)
{
	int j;
	int i;

	i = 0;
	while ((*map)->map[i])
	{
		printf("->%s\n", (*map)->map[i]);
		j = 0;
		while ((*map)->map[i][j])
		{
			if ((*map)->map[i][j] == '0')
			{
				if ((*map)->map[i][j - 1] == ' ' || (*map)->map[i][j + 1] == ' '\
				|| (*map)->map[i - 1][j] == ' ' || (*map)->map[i + 1][j] == ' ')
					put_error("MAP ISN'T SURRPOUNDED BY WALLS");
			}
			j++;
		}
		i++;
	}
}
