
#include "parsing.h"

void    map_parsing(t_map **map, int s)
{
	int j;

	while ((*map)->map[s])
	{
		j = 0;
		while ((*map)->map[s][j])
		{
			if ((*map)->map[s][j] == '0')
			{
				if ((*map)->map[s][j - 1] == ' ' || (*map)->map[s][j + 1] == ' '\
				|| (*map)->map[s - 1][j] == ' ' || (*map)->map[s + 1][j] == ' ')
				{
					printf("[%s]\n", (*map)->map[s]);
					// put_error("MAP ISN'T SURRPOUNDED BY WALLS");
				}
			}
			j++;
		}
		s++;
	}
}
