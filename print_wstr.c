/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 11:43:25 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		null_case(wchar_t *arg)
{
	if (!arg)
	{
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

size_t			display_space_w(t_mod *m,  size_t size)
{
	size_t		i;
	size_t		nospace;

	i = 0;
	if (GET(m->flag, F_HO))
		nospace = size + 1;
	else
		nospace = ((m->prec) ? MAX(m->prec, size)
					: size);
	while ((int)i < (m->length - (int)nospace))
	{
		if (GET(m->flag, F_ZERO))
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

size_t			display_wstr(t_mod *m, wchar_t *buf)
{
	size_t		cnt;
	char		tmp[5];
	int			i;
	size_t		sizew;

	i = 0;
	sizew = 0;
	while (buf[i])
	{
		ft_widetoa(tmp, 5, (int)(buf[i]));
		sizew += ft_strlen(tmp);
		i++;
	}
	cnt = sizew;
	if (!GET(m->flag, F_MINUS))
		cnt += display_space_w(m, sizew);
	while (*buf)
	{
		ft_widetoa(tmp, 5, (int)(*buf));
		ft_putstr(tmp);
		buf++;
	}
	if (GET(m->flag, F_MINUS))
		cnt += display_space_w(m, sizew);
	return (cnt);
}

int				print_wstr(t_mod *m, va_list ap)
{
	size_t		i;
	wchar_t		*arg;
	size_t		size;

	i = 0;
	(void)m;
	arg = va_arg(ap, wchar_t *);
	if (null_case(arg))
		return (6);
	size = display_wstr(m, arg);
/*	while (*arg)
	{
		ft_widetoa(buf, 5, (int)(*arg));
		size += ft_strlen(buf);
		ft_putstr(buf);
		arg++;
	}*/
	return (size);
}
