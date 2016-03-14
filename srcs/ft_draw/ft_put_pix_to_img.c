/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pix_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:26:56 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/14 14:26:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

#define CAST(type, ptr)				((type)(ptr))

void				put_pix_to_img(t_vec3i *v, t_image *i)
{
	int				off_x;
	int				off_y;

	off_x = (v->x);
	off_y = (W_HEIGHT - v->y) * W_WIDTH;
	if (v->x < 0 || v->y < 0
		|| v->x > W_WIDTH || v->y > W_HEIGHT)
		return ;
	CAST(int *, i->data)[off_x + off_y] = v->z;
}
