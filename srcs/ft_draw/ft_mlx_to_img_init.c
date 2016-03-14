/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_to_img_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:26:50 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/14 14:26:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"

int				ft_mlx_img_init(void *mlx_ptr, t_image *image, int width,
				int height)
{
	image->ptr = mlx_new_image(mlx_ptr, width, height);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line,
									&image->endian);
	image->width = width;
	image->height = height;
	return (0);
}
