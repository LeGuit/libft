/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:18:59 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 16:16:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (s2[j] != '\0'))
		{
			if (s2[i + j] == '\0')
				return (NULL);
			else
				j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
		n--;
	}
	return (NULL);
}
