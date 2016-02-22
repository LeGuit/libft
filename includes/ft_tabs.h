/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:27:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 14:28:17 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_TABS_H
# define _FT_TABS_H

# include <stdlib.h>

# include "ft_str.h"

char				**ft_tabdup(char **ptr);
void				ft_tabdel(char ***tab);
size_t				ft_tabsize(char **tab);

#endif
