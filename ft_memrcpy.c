/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:14:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 12:14:14 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdst;

	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	tsrc += n;
	tdst += n;
	while (n > 0)
	{
		*tdst = *tsrc;
		ft_putchar(*tdst);
		tdst--;
		tsrc--;
		n--;
	}
	return (dst);
}
