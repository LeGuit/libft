/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:33:27 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 12:12:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i + count != c])
		{
			count = 0;
			while (s[i + count] != c)
				count++;
			res[i] = ft_strnew(count + 1);
			while (count != 0)
			{
				res[j][count] = s[i + count];
				count--;
			}
			j++;
		}
		i++;
	}
	return (res);
}
