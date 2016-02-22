/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:10:09 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/22 14:15:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_DLST_H
# define _FT_DLST_H

# define C_NODE(type,ptr)	((type *)(ptr))

typedef struct		s_dlst
{
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

void				dlst_init(t_dlst *dlst);
void				dlst_add(t_dlst *new, t_dlst *prev, t_dlst *next);
void				dlst_add_head(t_dlst *new, t_dlst *dlst);
void				dlst_add_tail(t_dlst *new, t_dlst *dlst);
void				dlst_del(t_dlst *prev, t_dlst *next);
void				dlst_del_entry(t_dlst *entry);
void				dlst_replace(t_dlst *old, t_dlst *new);
void				dlst_replace_init(t_dlst *old, t_dlst *new);
void				dlst_del_init(t_dlst *entry);
void				dlst_move_head(t_dlst *entry, t_dlst *head);
void				dlst_move_tail(t_dlst *entry, t_dlst *head);
void				dlst_rotate(t_dlst *head);
void				dlst_rrotate(t_dlst *head);
int					dlst_empty(t_dlst *head);
int					dlst_is_last(t_dlst *dslt, t_dlst *head);
int					dlst_is_singular(t_dlst *head);
int					dlst_size(t_dlst *head);
void				dlst_swap(t_dlst *head);
void				dlst_cut_position(t_dlst *nlst, t_dlst *head,
					t_dlst *entry);
void				dlst_merge(t_dlst *heada, t_dlst *headb,
					int (*cmp)(t_dlst *, t_dlst *));
t_dlst				*dlst_go_to(t_dlst *head, int nb);
void				dlst_merge_sort(t_dlst *head,
					int (*cmp)(t_dlst *, t_dlst *));
void				dlst_rev(t_dlst *head);

#endif
