/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:16:17 by macbookair        #+#    #+#             */
/*   Updated: 2023/09/22 13:16:25 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    rgb_parse(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
	    if (str[i] == ',')
	    {
			if (i == 0 || i == (int)ft_strlen(str) - 1 || c >= 2)
				put_error("INVALID RGB");
			c++;
		}
		else if (!ft_isdigit(str[i]))
			put_error("INVALID RGB");
		i++;
	}
}
