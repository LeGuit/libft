/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 14:31:03 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
/*
static size_t	ft_wstrlen(const wchar_t *wstr)
{
	size_t		cnt;

	cnt = 0;
	if (wstr == NULL)
		return (0);
	while (wstr[cnt])
		cnt++;
	return (cnt);
}

static size_t	apply_prec(t_mod *m, wchar_t *arg)
{
	size_t		i;

	i = ft_wstrlen(arg);
	if (GET(m->flag, F_PREC))
	{
		if (m->prec)
		{
			i = MIN(i, m->prec);
		}
		else
			i = 0;
	}
	return (i);
}
*/
static int		null_case(wchar_t *arg)
{
	if (!arg)
	{
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

int				print_wstr(t_mod *m, va_list ap)
{
	char		buf[5];
	size_t		i;
	wchar_t		*arg;
	size_t		size;

	i = 0;
	(void)m;
	arg = va_arg(ap, wchar_t *);
	if (null_case(arg))
		return (6);
	size = 0;
	while (*arg)
	{
		ft_widetoa(buf, 5, (int)(*arg));
		size += ft_strlen(buf);
		ft_putstr(buf);
		arg++;
	}
	return (size);
}
