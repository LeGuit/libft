/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 19:39:48 by gwoodwar         ###   ########.fr       */
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
