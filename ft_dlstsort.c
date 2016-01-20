/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:24:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/20 19:50:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			dlst_cut_position(t_dlst *nlst, t_dlst *head, t_dlst *entry)
{
	t_dlst		*new;

	if (dlst_empty(head))
		return ;
	if (dlst_is_singular(head) && (head->next != entry && head != entry))
		return ;
	if (entry == head)
		dlst_init(nlst);
	else
	{
		new = entry->next;
		nlst->next = head->next;
		nlst->next->prev = nlst;
		nlst->prev = entry;
		entry->next = nlst;
		head->next = new;
		new->prev = head;
	}
}

void			dlst_merge(t_dlst *heada, t_dlst *headb,
		int (*cmp)(t_dlst *, t_dlst *))
{
	t_dlst		*ita;
	t_dlst		*itb;

	ita = heada->next;
	while (!dlst_empty(headb))
	{
		itb = headb->next;
		if (cmp(ita, itb))
		{
			dlst_del_entry(itb);
			dlst_add(itb, ita->prev, ita);
		}
		else
			ita = ita->next;
	}
}

t_dlst			*dlst_go_to(t_dlst *head, int nb)
{
	t_dlst		*it;

	it = head->next;
	while (nb)
	{
		it = it->next;
		nb--;
	}
	return (it);
}

int				dlst_is_sort(t_dlst *head, int (*cmp)(t_dlst *, t_dlst *))
{
	t_dlst		*it;

	it = head->next;
	while (it != head)
	{
		if (it->next != head)
		{
			if (cmp(it, it->next))
				return (0);
		}
		it = it->next;
	}
	return (1);
}

t_dlst			*dlst_merge_sort(t_dlst *head, int (*cmp)(t_dlst *, t_dlst *))
{
	t_dlst		newlst;
	int			size;

	if (dlst_is_singular(head))
		return (head);
	dlst_init(&newlst);
	size = dlst_size(head) / 2;
	dlst_cut_position(&newlst, head, dlst_go_to(head, size));
	head = dlst_merge_sort(head, cmp);
	dlst_merge(head, &newlst, cmp);
	return (head);
}
