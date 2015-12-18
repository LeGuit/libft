/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/18 12:02:00 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char		*get_arg_str(t_mod *m, va_list ap)
{
	if (GET(m->modif, MOD_L))
		return ((char *)va_arg(ap, wchar_t *));
	else
		return (va_arg(ap, char *));
}

static size_t	apply_prec(t_mod *m, char *arg)
{
	size_t		i;

	i = ft_strlen(arg);
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

int				print_str(t_mod *m, va_list ap)
{
	size_t		cnt;
	char		*arg;
	size_t		i;

	if (!(arg = get_arg_str(m, ap)))
	{
		ft_putstr("(null)");
		return (6);
	}
	cnt = apply_prec(m, arg);
	i = 0;
	if (GET(m->flag, F_MINUS))
	{
		while (i < cnt)
			ft_putchar(arg[i++]);
		cnt += ft_space(m, cnt);
	}
	else
	{
		cnt += ft_space(m, cnt);
		while (i < cnt)
			ft_putchar(arg[i++]);
	}
	return (cnt);
}
