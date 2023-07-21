/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:24:43 by fadermou          #+#    #+#             */
/*   Updated: 2022/11/02 23:38:46 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < dstsize - 1) && dstsize != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
