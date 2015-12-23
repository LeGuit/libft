/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 16:51:46 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	display_space_w(t_mod *m, size_t size)
{
	size_t		i;
	size_t		nospace;

	i = 0;
	nospace = size;
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

static size_t	sizew_to_print(t_mod *m, wchar_t *buf)
{
	int			i;
	size_t		sizew;
	char		tmp[5];

	i = 0;
	sizew = 0;
	while (buf[i] && (int)(m->prec ? m->prec : 1) > 0)
	{
		ft_widetoa(tmp, 5, (int)(buf[i]));
		sizew += ft_strlen(tmp);
		if (GET(m->flag, F_PREC))
			m->prec -= 5;
		i++;
	}
	return (sizew);
}

size_t			display_wstr(t_mod *m, wchar_t *buf)
{
	size_t		cnt;
	char		tmp[5];
	size_t		sizew;

	cnt = sizew_to_print(m, buf);
	sizew = cnt;
	if (!GET(m->flag, F_MINUS))
		cnt += display_space_w(m, cnt);
	if (GET(m->flag, F_PREC))
	{
		while ((int)sizew > 0)
		{
			ft_widetoa(tmp, 5, (int)(*buf));
			ft_putstr(tmp);
			buf++;
			sizew -= 4;
		}
	}
	else
	{
		while (*buf)
		{
			ft_widetoa(tmp, 5, (int)(*buf));
			ft_putstr(tmp);
			buf++;
		}
	}
	if (GET(m->flag, F_MINUS))
		cnt += display_space_w(m, cnt);
	return (cnt);
}

int				print_wstr(t_mod *m, va_list ap)
{
	size_t		i;
	wchar_t		*arg;
	size_t		size;

	i = 0;
	arg = va_arg(ap, wchar_t *);
	if (null_case((char *)arg))
		return (6);
	size = display_wstr(m, arg);
	return (size);
}
