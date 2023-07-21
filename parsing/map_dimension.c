/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:05:14 by macbookair        #+#    #+#             */
/*   Updated: 2023/07/21 16:55:03 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_fill_it(char *str, int len)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (i < len)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	// free (str);////leaks
	return (ret);
}

void    map_dimension(t_map **map)
{
    int i;

    i = 0;
    while ((*map)->map[i])
	{
        (*map)->map[i] = ft_fill_it((*map)->map[i], (*map)->m_x);
		i++;
    }
}
