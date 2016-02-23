/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:24:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/08 12:24:48 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xtoy.h"

int				ft_size_nb(int nb)
{
	int			i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
