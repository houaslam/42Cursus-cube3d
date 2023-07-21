/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:24:37 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/02 23:38:09 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char	*s1, const char *ss2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 || !ss2)
		return (NULL);
	result = ((char *)malloc(ft_strlen(s1) + ft_strlen(ss2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (ss2[j])
	{
		result[i] = ss2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
