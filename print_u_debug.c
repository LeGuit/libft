/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:23:06 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 16:40:55 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_ull	get_arg_u(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_HH))
		return ((t_ull)(unsigned char)va_arg(ap, int));
	if (GET(m->modif, MOD_H))
		return ((t_ull)(unsigned short)va_arg(ap, int));
	if (GET(m->modif, MOD_LL))
		return ((t_ull)va_arg(ap, unsigned long));
	if (GET(m->modif, MOD_L))
		return (va_arg(ap, t_ull));
	if (GET(m->modif, MOD_J))
		return ((t_ull)va_arg(ap, uintmax_t));
	if (GET(m->modif, MOD_Z))
		return ((t_ull)va_arg(ap, size_t));
	if (m->convers == 'p')
		return ((t_ull)va_arg(ap, void *));
	else
		return ((t_ull)va_arg(ap, unsigned int));
}

static int		zero_case(t_mod *m, t_ull arg, char *buf)
{
	if (arg == 0)
	{
		if (!GET(m->flag, F_HASH) || m->convers == 'u')
			return (0);
		buf[0] = '0';
		if (m->convers == 'x')
		{
			buf[1] = 'x';
			ft_ulltstr_base(arg, "0123456789abcdef", buf + 2);
			return (2);
		}
		if (m->convers == 'X')
		{
			buf[1] = 'X';
			ft_ulltstr_base(arg, "0123456789ABCDEF", buf + 2);
			return (2);
		}
		if (m->convers == 'o')
			ft_ulltstr_base(arg, "01234567", buf + 1);
		return (1);
	}
	return (0);
}

static int		hash_case(t_mod *m, t_ull arg, char *buf)
{
	if (!GET(m->flag, F_HASH) || m->convers == 'u')
		return (0);
	if (zero_case(m, arg, buf))
		return (1);
	ft_putchar('0');
	if (m->convers == 'x')
	{
		ft_putchar('x');
		ft_ulltstr_base(arg, "0123456789abcdef", buf);
		return (2);
	}
	if (m->convers == 'X')
	{
		ft_putchar('x');
		ft_ulltstr_base(arg, "0123456789ABCDEF", buf);
		return (2);
	}
	if (m->convers == 'o')
		ft_ulltstr_base(arg, "01234567", buf);
	return (1);
}

static size_t	get_buf(t_mod *m, t_ull arg, char *buf)
{
	size_t		ret;

	if ((ret = hash_case(m, arg, buf)))
			return (ret);
	if (m->convers == 'o')
		ft_ulltstr_base(arg, "01234567", buf);
	if (m->convers == 'x')
		ft_ulltstr_base(arg, "0123456789abcdef", buf);
	if (m->convers == 'X')
		ft_ulltstr_base(arg, "0123456789ABCDEF", buf);
	if (m->convers == 'u')
		ft_ulltstr_base(arg, "0123456789", buf);
	return (0);
}

int				print_u(t_mod *m, va_list ap)
{
	size_t		cnt;
	t_ull		arg;
	char		buf[128];

	arg = get_arg_u(m, ap);
	process_ptr(m);
	cnt = get_buf(m, arg, buf);
	if (GET(m->prec, F_PREC) && buf[0] == '0')
		buf[0] = 0;
	cnt += ft_strlen(buf);
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
