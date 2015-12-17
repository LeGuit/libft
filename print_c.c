/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/17 17:44:19 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

static int		get_arg_c(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_L))
		return ((int)(wint_t)va_arg(ap, int));
	else
		return ((int)(char)va_arg(ap, int));
}

int				print_c(t_mod *m, va_list ap)
{
	size_t		cnt;
	int			arg;
	char		buf[5];

	arg = get_arg_c(m, ap);
	ft_widetoa(buf, 5, arg);
	cnt = 1;
	if (GET(m->flag, F_MINUS))
	{
		ft_putstr(buf);
		cnt += ft_space(m, cnt);
	}
	else
	{
		cnt += ft_space(m, cnt);
		ft_putstr(buf);
	}
	return (cnt);
}
