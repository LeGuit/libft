/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:33:27 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 14:13:40 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	while (s[i])
	{
		count = 0;
		if (s[i + count != c])
		{
			while (s[i + count] != c)
				count++;
			res[i] = ft_strnew(count + 1);
			while (count > 0)
			{
				res[j][count] = s[i + count];
				count--;
			}
			j++;
			i += count;
		}
		i++;
	}
	return (res);
}*/

char	**ft_strsplit(char const *s, char c)
{
	int		count;
	char	*tmp;
	char	**res;
	int		index;

	res = NULL;
	index = 0;
	while(*s)
	{
		count = 0;
		if (*s != c)
		{
			tmp = (char *)s;
			while (*tmp != c)
			{
				count++;
				tmp++;
			}
			res[index] = ft_strnew(count + 1);
			res[index] = ft_strncpy(res[index], s, count + 1);
		}
		index++;
		s++;
	}
	return (res);
}
