/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:16:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 10:59:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdst;

	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	while (n > 0)
	{
		if (*tsrc != c)
		{
			*tdst = *tsrc;
			tsrc++;
			tdst++;
			dst++;
			n--;
		}
		else
			break ;
	}
	if (n == 0)
		return (NULL);
	else
		return (dst);
}
