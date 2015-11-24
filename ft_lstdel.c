/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:26:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/23 18:26:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tmp;

	while ((*alst)->next)
	{
		*tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(tmp, del((*tmp)->content, (*tmp)->content_size));
	}
}
