/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:24:58 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/02 23:39:39 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	len = ft_strlen(s);
	len--;
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}
