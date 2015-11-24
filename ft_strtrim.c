/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:32:11 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/23 17:32:51 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;
	size_t	j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	s += (ft_strlen(s) - 1);
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		i++;
		s--;
	}
	res = ft_strnew(i);
	i = 0;
	while (i < ft_strlen(res))
	{
		res[i] = s[j + i];
		i++;
	}
	return (res);
}
