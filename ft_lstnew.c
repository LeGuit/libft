/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:24:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 11:32:29 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res_list;

	if (!(res_list = (t_list*)malloc(sizeof(*content) * content_size)))
		return (NULL);
	else
	{
		res_list->content = (void *)content;
		res_list->next = NULL;
	}
	return (res_list);
}
