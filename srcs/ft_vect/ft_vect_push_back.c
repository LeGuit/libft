/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:54:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 13:54:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vect.h"

int				ft_vect_push_back(t_vect *vect, void *src)
{
	void		*tmp;

	if (vect->capacity == vect->size)
	{
		tmp = vect->data;
		vect->capacity = (vect->capacity ? vect->capacity * 2 : 1);
		vect->data = malloc(vect->capacity * vect->element_size);
		if (!vect->data)
			return (1);
		ft_memcpy(vect->data, tmp, vect->size * vect->element_size);
		free(tmp);
	}
	ft_memcpy(ft_vect_at(vect, vect->size), src, vect->element_size);
	vect->size++;
	return (0);
}
