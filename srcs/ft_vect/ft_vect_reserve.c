/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:55:54 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 13:56:00 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_vect.h"

int				ft_vect_reserve(t_vect *vect, size_t reserve)
{
	void		*tmp;

	if (reserve <= vect->capacity)
		return (1);
	tmp = vect->data;
	vect->data = malloc(reserve * vect->element_size);
	if (!vect->data)
		return (1);
	vect->data = ft_memcpy(vect->data, tmp, vect->size);
	free(tmp);
	vect->capacity = reserve;
	return (0);
}
