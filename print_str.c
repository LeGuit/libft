/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:27:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/23 10:19:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		null_case(char *arg)
{
	if (!arg)
	{
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

size_t			display_str(t_mod *m, char *buf)
{
	size_t		cnt;
	int			i;

	cnt = 0;
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	i = 0;
	while (buf[i])
		ft_putchar(buf[i++]);
	cnt += ft_strlen(buf);
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	return (cnt);
}

int				print_str(t_mod *m, va_list ap)
{
	size_t		cnt;
	char		*arg;

	arg = va_arg(ap, char *);
	if (null_case(arg))
		return (6);
	cnt = display_str(m, arg);
	return (cnt);
}
