/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:17:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/26 13:23:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			dslt_rev(t_dlst *head)
{
	t_dlst		*tmp;

	tmp = head->prev;
	while (head->next != tmp)
		dlst_rotate(head);
}
