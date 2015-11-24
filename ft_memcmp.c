/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:31:28 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 20:38:17 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	else
	{
		while (n != 0)
		{
			if ((unsigned char *)s1 != (unsigned char *)s2)
				return ((unsigned char *)s1 - (unsigned char *)s2);
			n--;
			s1++;
			s2++;
		}
		return (0);
	}
}
