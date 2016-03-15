/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:23:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/14 14:24:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_DRAW_H
# define _FT_DRAW_H

# define W_WIDTH				800
# define W_HEIGHT				600

typedef struct		s_view
{
	float			xmax;
	float			xmin;
	float			ymax;
	float			ymin;
}					t_view;

typedef struct		s_vec3i
{
	int				x;
	int				y;
	int				z;
}					t_vec3i;

typedef struct		s_image
{
	void			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
	int				width;
	int				height;
}					t_image;

void				ft_put_pix_to_img(t_vec3i *v, t_image *i);
int					mix_color(int c1, int c2, float lambda);
#endif
