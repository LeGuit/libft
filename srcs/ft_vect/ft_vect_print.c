/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:57:49 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 13:57:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vect.h"

void				ft_vect_print(t_vect *vector, void (*print)())
{
	size_t			i;

	i = 0;
	while (i < vector->size)
	{
		print(ft_vect_at(vector, i));
		i++;
	}
}
