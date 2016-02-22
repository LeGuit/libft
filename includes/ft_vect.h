/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:28:33 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 14:29:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_VECT_H
# define _FT_VECT_H

# include <stddef.h>
# include <stdlib.h>

# include "ft_mem.h"

# define VECT_INI(type)		(t_vect){NULL, 0, 0, sizeof((type))}

typedef struct		s_vect
{
	void			*data;
	size_t			size;
	size_t			capacity;
	size_t			element_size;
}					t_vect;

int					ft_vect_push_back(t_vect *vect, void *buf);
int					ft_vect_reserve(t_vect *vect, size_t reserve);
int					ft_vect_del(t_vect *vect, int (*del)(void *));

#endif
