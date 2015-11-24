/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 11:36:09 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res_lst;
	t_list	*tmp;

	res_lst = NULL;
	while (lst->next)
	{
		tmp = ft_lstnew(f(lst), sizeof(lst));
		ft_lstadd_last(res_lst, tmp);
	}
	return (res_lst);
}
