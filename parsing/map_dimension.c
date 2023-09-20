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

void	end_of_map(t_map **map)
{
	int	i;
	int	j;

	i = (*map)->m_y;
	j = 0;
	while ((*map)->map[i])
	{
		if (ft_strcmp((*map)->map[i], ";"))
			break;
		i--;
		j++;
	}
	printf("J == %d\n", j);
	// (*map)->m_y = (*map)->m_y - j + 1;
	printf("%d\n", (*map)->m_y);
}

char	*ft_join(char *ret, char c)
{
	if (c == '1')
		ret = ft_strjoin(ret, "1");
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
		ret = ft_strjoin(ret, "    ");
	else if (c != ';')
		put_error("INVALID CHARACTER");
	return (ret);
}


void	empty_line(char **str, int i)
{
	while (str[i])
	{
		if (ft_strcmp(str[i], ";"))
			break;
		i++;
	}
	if (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		put_error("INVALID MAP");
	}
}

char	*ft_fill_it(char *str, t_map **map)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strcmp(str, ";"))
			j = 1;
		else if (j && ft_strcmp(str, ";"))
			put_error("EMPTY LINE");

			// empty_line(str, i);
		ret = ft_join(ret, str[i]);
		i++;
	}
	while (i < (*map)->m_x)
	// while ((int)ft_strlen(ret) < (*map)->m_x - 1)
	{
		if ((int)ft_strlen(ret) < (*map)->m_x - 1)/////TO CHECK FIRST
			ret = ft_strjoin(ret, " ");
		i++;
	}
	free (str);
	return (ret);
}

void    map_dimension(t_map **map, int i)
{
	int	end;

	end = 0;
	printf("[%s]\n", (*map)->map[i]);
	printf("[%d]\n", i);
	end_of_map(map);
	while ((*map)->map[i] && end < (*map)->m_y)
	{
		if (!ft_strcmp((*map)->map[i], ";"))
			empty_line((*map)->map, i);
		(*map)->map[i] = ft_fill_it((*map)->map[i], map);
		i++;
		end++;
	}
	
}
