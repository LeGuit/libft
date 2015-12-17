/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:12:43 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/15 19:00:27 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				ft_vprintf(const char *format, va_list ap)
{
	t_mod		m;
	size_t		i;
	int			ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_bzero(&m, sizeof(t_mod));
			i += get_mod(&format[i + 1], &m, ap) + 1;
			ret += print_arg(&m, ap);
			continue ;
		}
		ft_putchar(format[i]);
		ret++;
		i++;
	}
	return (ret);
}
