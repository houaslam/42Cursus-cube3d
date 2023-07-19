/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:49:56 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/17 20:43:48 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update(char *sta_str)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (sta_str[i] != '\n' && sta_str[i])
		i++;
	if (!sta_str[i])
	{
		free(sta_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(sta_str) - i));
	if (!str)
		return (NULL);
	i++;
	while (sta_str[i])
		str[j++] = sta_str[i++];
	str[j] = '\0';
	free (sta_str);
	return (str);
}

char	*str_n(char *sta_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!sta_str[i])
		return (NULL);
	while (sta_str[i] && sta_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (sta_str[i] != '\n' && sta_str[i])
	{
		str[i] = sta_str[i];
		i++;
	}
	if (sta_str[i] == '\n')
	{
		str[i] = sta_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_nd_join(char *str, int fd)
{
	int		read_b;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_b = 1;
	while (!ft_strchr(str, '\n') && read_b != 0)
	{
		read_b = read(fd, buff, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[read_b] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*sta_str;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sta_str = read_nd_join(sta_str, fd);
	if (!sta_str)
		return (NULL);
	ret_line = str_n(sta_str);
	sta_str = update(sta_str);
	return (ret_line);
}
