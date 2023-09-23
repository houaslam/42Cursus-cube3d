/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:56:12 by fadermou          #+#    #+#             */
/*   Updated: 2023/09/21 18:22:43 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_file(char **av)
{
	int	i;
	int	fd;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
			break ;
		i++;
	}
	if (i == 0 || av[1][i + 1] != 'c' || av[1][i + 2] != 'u' \
	|| av[1][i + 3] != 'b' || av[1][i + 4] != '\0')
		put_error("FILE MUST BE ENDED BY \".cub\"!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		put_error("NO SUCH A FILE OR DIRECTORY");
	return (fd);
}

void	read_map(t_map **map, char **av)
{
	int	fd;
	char	*tmp;
	char	*str;

	fd = check_file(av);
	tmp = get_next_line(fd);
	str = ft_strdup("");///.to be changed 
	while (1)
	{
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
		{
			free(tmp);
			tmp = ft_strdup(";\n");
			// printf("there is an empty line");
		}
		str = ft_strjoin(str, tmp);
		// printf("-->%s\n", tmp);
		// printf("-->%d\n", );
		// free(tmp);
		tmp = get_next_line(fd);
	}
	(*map)->map = ft_split(str, '\n');
	// free (str);
}
