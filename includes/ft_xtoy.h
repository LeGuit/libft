/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:48:38 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 15:49:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_XTOY_H
# define _FT_XTOY_H

# include <stddef.h>

# include "ft_is.h"
# include "ft_macro.h"
# include "ft_str.h"
# include "ft_mem.h"

int					ft_size_nb(int nb);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
long int			ft_atoll(const char *str);
char				*ft_itoa(int n);
void				ft_ulltstr_base(unsigned long long n, char *base_strm,
											char *buf);
void				ft_slltstr(long long n, char *buf);

#endif
