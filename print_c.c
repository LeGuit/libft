/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/16 15:41:48 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

static char		get_arg_c(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_L))
		return ((wint_t)va_arg(ap, int));
	else
		return ((char)va_arg(ap, int));
}

int				print_c(t_mod *m, va_list ap)
{
	size_t		cnt;
	char		arg;

	arg = get_arg_c(m, ap);
	cnt = 1;
	if (GET(m->flag, F_MINUS))
	{
		ft_putchar(arg);
		cnt += ft_space(m, cnt);
	}
	else
	{
		cnt += ft_space(m, cnt);
		ft_putchar(arg);
	}
	return (cnt);
}
