/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:12:43 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 16:24:19 by gwoodwar         ###   ########.fr       */
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
			if (!format[i + 1])
				return (0);
			ft_bzero(&m, sizeof(t_mod));
			i += get_mod(&format[i + 1], &m, ap) + 1;
			if (m.convers)
			{
				ret += print_arg(&m, ap);
				continue ;
			}
			if (!m.convers)
				ret += ft_space(&m, 1); 
		}
		ft_putchar(format[i]);
		ret++;
		i++;
	}
	return (ret);
}
