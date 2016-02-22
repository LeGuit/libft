/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:51:50 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 15:53:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MACRO_H
# define _FT_MACRO_H

# define ABS(x)				((x > 0) ? (x) : -(x))
# define MIN(x, y)			((x) > (y) ? (y) : (x))
# define MAX(x, y)			((x) < (y) ? (y) : (x))

# define GET(i, mask)		(i & mask)
# define SET(i, mask)		(i |= mask)
# define UNSET(i, mask)		(i &= ~(mask))
# define TOGGLE(i, mask)	(i ^= mask)
# define PRINT(i, mask)		ft_putchar(GET(i, mask) ? '1' : '0')

#endif
