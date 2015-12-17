/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:13:04 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/17 13:17:51 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		process_flags(t_mod *m)
{
	if (ft_strchr("sdipc", m->convers) && GET(m->flag, F_HASH))
		TOGGLE(m->flag, F_HASH);
	if (GET(m->flag, F_ZERO) && m->prec && ft_strchr("dDioOuUixX", m->convers))
		TOGGLE(m->flag, F_ZERO);
	if (GET(m->flag, F_ZERO) && GET(m->flag, F_MINUS))
		TOGGLE(m->flag, F_ZERO);
	if (GET(m->flag, F_SPACE) && ft_strchr("oOuUxXD", m->convers))
		TOGGLE(m->flag, F_SPACE);
	if (GET(m->flag, F_SPACE) && GET(m->flag, F_PLUS))
		TOGGLE(m->flag, F_SPACE);
	if (GET(m->flag, F_PREC) && ft_strchr("dDioOuUixX", m->convers))
	{
		SET(m->flag, F_ZERO);
		((m->length) ? (m->length) : (m->length = m->prec));
	}//case if length & prec with blanks and 0
}

void		process_modifier(t_mod *m)
{
	if (ft_strchr("DOCUS", m->convers))
	{
		UNSET(m->modif, MOD_ALL);
		SET(m->modif, MOD_L);
		m->convers = ft_tolower(m->convers);
	}
}

void		process_ptr(t_mod *m)
{
	if (m->convers == 'p')
	{
		SET(m->flag, F_HASH);
		m->convers = 'x';
	}
}
