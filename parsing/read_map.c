/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:56:12 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/30 07:39:55 by houaslam         ###   ########.fr       */
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
	str = NULL;
	while (1)
	{
		if (tmp[0] == '\n')
		{
			free(tmp);
			tmp = ft_strdup(";\n");
			// printf("there is an empty line");
		}
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
	}
	(*map)->map = ft_split(str, '\n');
	free (str);
}
