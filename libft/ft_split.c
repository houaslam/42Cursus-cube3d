/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:53:35 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/03 00:25:10 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	ftstart(const char *s, char c, int i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int	ftend(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_freestr(char **s, int i)
{
	while (s >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		count;
	char	**p;
	int		end;

	if (!s)
		return (NULL);
	count = ftcount(s, c);
	p = malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < count)
	{
		start = ftstart(s, c, start);
		end = ftend(s, c, start);
		p[i] = ft_substr(s, start, end - start);
		if (!p[i])
			return (ft_freestr(p, i - 1));
		start = end + 1;
	}
	p[i] = NULL;
	return (p);
}
