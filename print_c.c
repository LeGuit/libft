/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 14:59:10 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

static int		get_arg_c(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_L))
		return ((int)va_arg(ap, wint_t));
	else
		return (va_arg(ap, int));
}

int				print_c(t_mod *m, va_list ap)
{
	size_t		cnt;
	int			arg;
	char		buf[5];

	arg = get_arg_c(m, ap);
	if (!GET(m->modif, MOD_L) && arg > 127)
	{
		ft_putchar(arg);
		return (1);
	}
	ft_widetoa(buf, 5, arg);
	cnt = (ft_strlen(buf) ? ft_strlen(buf) : 1);
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
	if (!*buf)
		ft_putchar('\0');
	return (cnt);
}
