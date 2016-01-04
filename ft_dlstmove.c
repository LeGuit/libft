/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:28:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 14:04:51 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		dlst_move_head(t_dlst *dlst, t_dlst *head)
{
	dlst_del_entry(dlst);
	dlst_add_head(dlst, head);
}

void		dlst_move_tail(t_dlst *dlst, t_dlst *head)
{
	dlst_del_entry(dlst);
	dlst_add_tail(dlst, head);
}

void		dlst_rotate(t_dlst *head)
{
	t_dlst	*top;

	if (!dlst_empty(head))
	{
		top = head->next;
		dlst_move_tail(top, head);
	}
}

void		dlst_rrotate(t_dlst *head)
{
	t_dlst	*bot;

	if (!dlst_empty(head))
	{
		bot = head->prev;
		dlst_move_head(bot, head);
	}
}
