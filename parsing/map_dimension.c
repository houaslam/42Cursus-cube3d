/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:05:14 by macbookair        #+#    #+#             */
/*   Updated: 2023/07/29 15:33:16 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	replace_tabs(char *ret, int i)
{
	int	j;

	j = 4;
	while (j--)
	{
		ret[i] = ' ';
		i++;
	}
	return (4);
}

char	*ft_join(char *ret, char c, t_map **map)
{
	if (c == '1')
	{
		printf("here\n");
		ret = ft_strjoin(ret, "1");
		printf("%s\n", ret);
	}
	else if (c == '0')
		ret = ft_strjoin(ret, "0");
	else if (c == 'N')
		ret = ft_strjoin(ret, "N");
	else if (c == 'E')
		ret = ft_strjoin(ret, "E");
	else if (c == 'S')
		ret = ft_strjoin(ret, "S");
	else if (c == 'W')
		ret = ft_strjoin(ret, "W");
	else if (c == ' ')
		ret = ft_strjoin(ret, " ");
	else if (c == '\t')
	{
		(*map)->m_x += 3;
		ret = ft_strjoin(ret, "\t");
	}
	return (ret);
}

char	*ft_fill_it(char *str, t_map **map)
{
	char	*ret;
	int		i;
	// int		j;

	// ret = malloc(sizeof(char) * len + 100);
	ret = NULL;
	i = 0;
	// j = 0;
	while (str[i])
	{
		// if (str[i] == '\t')
		// 	// j += replace_tabs(ret, j);
		// 	ret = ft_strjoin(ret, "    ");
		// else
			// ret[j] = str[i];
			ret = (ft_join(ret, str[i], map));
		i++;
		// j++;
	}
	while (i < (*map)->m_x)
	{
		// ret[j] = ' ';
		if ((int)ft_strlen(ret) < (*map)->m_x)/////TO CHECK FIRST
		ret = ft_strjoin(ret, " ");
		printf("->%zu\n", ft_strlen(ret));
		i++;
	}
	// ret[j] = '\0';
	free (str);////leaks
	return (ret);
}

void    map_dimension(t_map **map, int i)
{
	// i = 0;
    while ((*map)->map[i])
	{
        (*map)->map[i] = ft_fill_it((*map)->map[i], map);
		i++;
    }
}
