/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:36:03 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/02 23:38:25 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	r;
	size_t	j;
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	d = ft_strlen(dest);
	r = ft_strlen(src);
	if (dstsize <= d)
		return (dstsize + r);
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && (j < dstsize - d - 1))
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (d + r);
}
