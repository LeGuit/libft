/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:15:43 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 14:15:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vect.h"

void				*ft_vect_at(t_vect *vect, size_t i)
{
	return (vect->data + (i * (vect->element_size)));
}