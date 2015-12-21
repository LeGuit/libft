/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:11:30 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/21 18:12:58 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	display_prefix(t_mod *m)
{
	if (GET(m->flag, F_HASH) && m->convers == 'x')
		ft_strcpy(m->prefix, "0x");
	if (GET(m->flag, F_HASH) && m->convers == 'X')
		ft_strcpy(m->prefix, "0X");
	if (GET(m->flag, F_PLUS) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "+");
	if (GET(m->flag, F_NEG) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "-");
	return (ft_strlen(m->prefix));
}

static size_t	display_zero(t_mod *m, char *buf)
{
	size_t		i;

	i = 0;
	while (i < (m->prec - ft_strlen(buf)))
	{
		ft_putchar('0');
		i++;
	}
	m->length -= i;
	return (i);
}

static size_t	display_space(t_mod *m)
{
	size_t		i;

	i = 0;
	while (i < (m->length))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

size_t			ft_display(t_mod *m, char *buf)
{
	size_t		cnt;

	cnt = 0;
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m);
	cnt += display_prefix(m);
	ft_putstr(m->prefix);
	cnt += display_zero();
	ft_putstr(buf);
	cnt += ft_strlen(buf);
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m);
	return (cnt);
}

int				print_modulo(t_mod *m, va_list ap)
{
	(void)ap;
	(void)m;
	ft_putchar('%');
	return (1);
}
