/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:26:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 12:35:14 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	if (size == 0)
		return (0);
	else if (dst_size == sizeof(dst) - 1)
		return (0);
	else
	{
		i = 0;
		while (i < sizeof(dst) - dst_size)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i ] = '\0';
	}
	return (sizeof(dst) - dst_size);
}
