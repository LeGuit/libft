/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:42:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/17 11:56:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_ll		get_arg_sign(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_HH))
		return ((t_ll)(signed char)va_arg(ap, int));
	if (GET(m->modif, MOD_H))
		return ((t_ll)(short)va_arg(ap, int));
	if (GET(m->modif, MOD_LL))
		return ((t_ll)va_arg(ap, long));
	if (GET(m->modif, MOD_L))
		return (va_arg(ap, t_ll));
	if (GET(m->modif, MOD_J))
		return ((t_ll)va_arg(ap, intmax_t));
	if (GET(m->modif, MOD_Z))
		return ((t_ll)va_arg(ap, int));
	else
		return ((t_ll)va_arg(ap, int));
}

static void		get_buf(t_mod *m, t_ll arg, char *buf)
{
	if ((GET(m->flag, F_SPACE) || GET(m->flag, F_PLUS)) && arg > 0)
	{
		if (GET(m->flag, F_SPACE))
			buf[0] = ' ';
		if (GET(m->flag, F_PLUS))
			buf[0] = '+';
		ft_slltstr(arg, buf + 1);
	}
	else if (arg < 0 && GET(m->flag, F_ZERO))
	{
		ft_putchar('-');
		if (arg == -2147483648)
			buf = "2147483648";
		else
			ft_slltstr(ABS(arg), buf);
	}
	else
		ft_slltstr(arg, buf);
}

int				print_sign(t_mod *m, va_list ap)
{
	size_t		cnt;
	t_ll		arg;
	char		buf[128];

	arg = get_arg_sign(m, ap);
	get_buf(m, arg, buf);
	if (!m->prec && buf[0] == '0')
		buf[0] = 0;
	cnt = ft_strlen(buf);
	if (arg < 0 && GET(m->flag, F_ZERO) && !GET(m->flag, F_PREC))
		cnt++;
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
