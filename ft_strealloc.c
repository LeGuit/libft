/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:14:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 11:18:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strealloc(char *str, size_t size)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_strnew(ft_strlen(str) + size)))
		return (NULL);
	ft_strcpy(str, tmp);
	free (tmp);
	return (str);
}
