/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:02:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 10:22:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)malloc(size)))
		return (NULL);
	else
	{
		while (size != 0)
		{
			res[size] = 0;
			size--;
		}
		return (res);
	}
}
