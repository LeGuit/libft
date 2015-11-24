/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:41:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 11:34:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last(t_list *alst, t_list *new)
{
	if (alst == NULL)
		alst = new;
	else
	{
		while (alst->next)
			alst = alst->next;
		alst = new;
	}
}
